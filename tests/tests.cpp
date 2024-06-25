#include <string>
#include <vector>
#include <iostream>
#include "../catch/catch.hpp"
#include "../readFromFile.h"
#include "../Vertex.h"
#include "../Dijkstras.h"
#include "../AStar.h"
#include "../BFS.h"


TEST_CASE("Verify that file_to_string works on a small example") {
	FileReader test;
	std::string res = test.file_to_string("tests/small.txt");
	// always check "expected" == "actual" --> be consistent
	REQUIRE("hello\nstudents\nof\ncs\n225\n!!!\n" == res);
}

TEST_CASE("Verify that file_to_vector works on a small example") {
	FileReader test;
	std::vector<std::string> res = test.file_to_vector("tests/small.txt");
	std::string expected[] = {"hello", "students", "of", "cs", "225", "!!!"};
	
	REQUIRE(6 == res.size());

	for (size_t i = 0; i < res.size(); i++) {
		REQUIRE(expected[i] == res[i]);
	}
}


TEST_CASE("Verify Djikstra's Algorithm with Harder Test Case") {

	//   harder Djikstra Test  case

	/**
	 *           ohare   -  jfk   - mia
	 * 		    /	 \       |      /
	 * 		   /	   \	 |	  /		 
	 * 		  /			 \	 |	/	
	 *     lax  ---------  sfo 
	 * 
	 * 	weight sfo : 1/4
	 *  weight lax : 1/2
	 *  weight ohare : 1/3
	 *  weight mia 1/2
	 *  weight jfk : 1/3
	 * EXPECTED ROUTES FROM LAX TO MIA : LAX->SFO->MIA 
	 * 
	 * 		
	 */ 
	
	Vertex * jfk = new Vertex(0, "jfk");
	Vertex * ohare = new Vertex(1, "ohare");
	Vertex * lax = new Vertex(2, "lax");
	Vertex * sfo = new Vertex(5, "sfo");
	Vertex * mia = new Vertex(3, "mia");
	//adjacency vector of each airport
	std::vector<Vertex*> jfkAdj;
	std::vector<Vertex*> ohareAdj;
	std::vector<Vertex*> laxAdj;
	std::vector<Vertex*> sfoAdj;
	std::vector<Vertex*> miaAdj;

	//JFK adj 1/3
	jfkAdj.push_back(ohare);
	jfkAdj.push_back(sfo);
	jfkAdj.push_back(mia);

	//OHARE adj 1/3 
	ohareAdj.push_back(jfk);
	ohareAdj.push_back(sfo);
	ohareAdj.push_back(lax);

	//mia adj 1/2
	miaAdj.push_back(jfk);
	miaAdj.push_back(sfo);

	//sfo 1/4
	sfoAdj.push_back(lax);
	sfoAdj.push_back(ohare);
	sfoAdj.push_back(jfk);
	sfoAdj.push_back(mia);

	//lax 1/2
	laxAdj.push_back(ohare);
	laxAdj.push_back(sfo);

	//set adjacency
	jfk->setAdjacency(jfkAdj);
	ohare->setAdjacency(ohareAdj);
	lax->setAdjacency(laxAdj);
	sfo->setAdjacency(sfoAdj);
	mia->setAdjacency(miaAdj);

	
	//vector of all airport
	std::vector<Vertex*> airport;
	airport.push_back(jfk);
	airport.push_back(ohare);
	airport.push_back(lax);
	airport.push_back(sfo);
	airport.push_back(mia);

	//make graph
	DGraph * airportGraph = new DGraph(airport);

	//find shortest path between lax to mia, expect lax sfo mia
	std::vector<Vertex*> sol = airportGraph->findShortest(lax, mia);
	
	std::vector<Vertex*> realSolution;
	realSolution.push_back(sfo);
	realSolution.push_back(mia);
	

	delete airportGraph;
	REQUIRE ( sol == realSolution );
		
}

TEST_CASE("Verify A Star Path Finding Algorithm") {
	
	//   A Star Test cases

	/**
	 *           b    - ---- c ---- -d  
	 * 		    /	 \       |      /
	 * 		   /	   \	 |	  /		 
	 * 		  /			 \	 |	/	
	 *     a   ---------     e  
	 * 
	 * 	weight e : 1/4
	 *  weight a : 1/2
	 *  weight b : 1/3
	 *  weight d 1/2
	 *  weight c  : 1/3
	 * EXPECTED ROUTES FROM LAX TO MIA : LAX->SFO->MIA 
	 * 
	 * 		
	 */ 
	
	Vertex * c = new Vertex(0, "jfk");
	Vertex * b = new Vertex(1, "ohare");
	Vertex * a = new Vertex(2, "lax");
	Vertex * e = new Vertex(5, "sfo");
	Vertex * d = new Vertex(3, "mia");
	//adjacency vector of each airport
	std::vector<Vertex*> aAdj;
	std::vector<Vertex*> bAdj;
	std::vector<Vertex*> cAdj;
	std::vector<Vertex*> dAdj;
	std::vector<Vertex*> eAdj;

	aAdj.push_back(b);
	aAdj.push_back(e);
	

	bAdj.push_back(a);
	bAdj.push_back(e);
	bAdj.push_back(c);
	
	cAdj.push_back(b);
	cAdj.push_back(e);
	cAdj.push_back(d);
	

	//sfo 1/4
	dAdj.push_back(c);
	dAdj.push_back(e);

	eAdj.push_back(c);
	eAdj.push_back(d);
	eAdj.push_back(b);
	eAdj.push_back(a);

	//set adjacency
	a->setAdjacency(aAdj);
	b->setAdjacency(bAdj);
	c->setAdjacency(cAdj);
	d->setAdjacency(dAdj);
	e->setAdjacency(eAdj);

	
	//vector of all airport
	std::vector<Vertex*> testSuit;
	testSuit.push_back(a);
	testSuit.push_back(b);
	testSuit.push_back(c);
	testSuit.push_back(d);
	testSuit.push_back(e);

	//make graph
	AStar * air = new AStar(testSuit);

	//find shortest path between lax to mia, expect lax sfo mia
	std::vector<Vertex*> sol = air->shortest(a, d);
	delete air;

	std::vector<Vertex*> realSolution;
	realSolution.push_back(e);
	realSolution.push_back(d);
	REQUIRE ( sol == realSolution );
	
}
TEST_CASE("Shortest Distance between Vertices BFS") {
	// Give different weights, initialize vertex
	//
	//   harder Djikstra Test  case

	/**
	 *           ohare   -  jfk   - mia
	 * 		    /	 \       |      /
	 * 		   /	   \	 |	  /		 
	 * 		  /			 \	 |	/	
	 *     lax  ---------  sfo 
	 * 
	 * 	weight sfo : 1/4
	 *  weight lax : 1/2
	 *  weight ohare : 1/3
	 *  weight mia 1/2
	 *  weight jfk : 1/3
	 * EXPECTED ROUTES FROM LAX TO MIA : LAX->SFO->MIA 
	 * 
	 * 		
	 */ 
	
	Vertex * jfk = new Vertex(0, "jfk");
	Vertex * ohare = new Vertex(1, "ohare");
	Vertex * lax = new Vertex(2, "lax");
	Vertex * sfo = new Vertex(5, "sfo");
	Vertex * mia = new Vertex(3, "mia");
	//adjacency vector of each airport
	std::vector<Vertex*> jfkAdj;
	std::vector<Vertex*> ohareAdj;
	std::vector<Vertex*> laxAdj;
	std::vector<Vertex*> sfoAdj;
	std::vector<Vertex*> miaAdj;

	//JFK adj 1/3
	jfkAdj.push_back(ohare);
	jfkAdj.push_back(sfo);
	jfkAdj.push_back(mia);

	//OHARE adj 1/3 
	ohareAdj.push_back(jfk);
	ohareAdj.push_back(sfo);
	ohareAdj.push_back(lax);

	//mia adj 1/2
	miaAdj.push_back(jfk);
	miaAdj.push_back(sfo);

	//sfo 1/4
	sfoAdj.push_back(lax);
	sfoAdj.push_back(ohare);
	sfoAdj.push_back(jfk);
	sfoAdj.push_back(mia);

	//lax 1/2
	laxAdj.push_back(ohare);
	laxAdj.push_back(sfo);

	//set adjacency
	jfk->setAdjacency(jfkAdj);
	ohare->setAdjacency(ohareAdj);
	lax->setAdjacency(laxAdj);
	sfo->setAdjacency(sfoAdj);
	mia->setAdjacency(miaAdj);

	
	//vector of all airport
	std::vector<Vertex*> airport;
	airport.push_back(jfk);
	airport.push_back(ohare);
	airport.push_back(lax);
	airport.push_back(sfo);
	airport.push_back(mia);

	//make graph
	BFS * airportGraph = new BFS(airport);

	//find shortest path between lax to mia, expect lax sfo mia
	std::vector<Vertex*> sol = airportGraph->shortestPath(lax, mia);
	
	/*
	for (auto it : sol) {
		std::cout<<it->getName()<<std::endl;
	}
	*/
	std::vector<Vertex*> realSolution;
	realSolution.push_back(sfo);
	realSolution.push_back(mia);
	delete airportGraph; 
	REQUIRE ( sol == realSolution );
		
}
TEST_CASE("Test case of file_to_vector") {
	FileReader * test = new FileReader();
	std::vector<std::string> smallSample = test->file_to_vector("tests/smallSample.txt");
	//std::cout<<smallSample.size()<<std::endl;
	std::string first = "hello my friend";
	std::string second = "my name is Michael";
	std::string third = "I'm from Vietnam";
	std::vector<std::string> realSol;
	realSol.push_back(first);
	realSol.push_back(second);
	realSol.push_back(third);
	
	delete test;
	REQUIRE(smallSample == realSol);


}


TEST_CASE("ReadFromFile test of getItemFromAirport()") {
	FileReader * test = new FileReader();
	std::vector<std::string> testAirplane = test->file_to_vector("tests/smallAirports.txt");
	std::vector<Vertex*> returnVertex = test->getItemFromAirport(testAirplane);
	std::pair<double, double> pair = {43.449902,39.9566 };
	Vertex * sochi = new Vertex({2965, pair, "Sochi International Airport"});
	Vertex * solVertex = returnVertex[0];
	REQUIRE (solVertex->getID() == sochi->getID());
	REQUIRE (solVertex->getName() == sochi->getName());
	REQUIRE (solVertex->getCoords() == sochi->getCoords());

	delete sochi;
	delete test;

}

TEST_CASE("BFS full traversal") {
	// Give different weights, initialize vertex
	//
	//   BFS full traversal

	/**
	 *           ohare   -  jfk   - mia
	 * 		    /	 \       |      /
	 * 		   /	   \	 |	  /		 
	 * 		  /			 \	 |	/	
	 *     lax  ---------  sfo 
	 * 
	 * 	weight sfo : 1/4
	 *  weight lax : 1/2
	 *  weight ohare : 1/3
	 *  weight mia 1/2
	 *  weight jfk : 1/3
	 * EXPECTED ROUTES FROM LAX TO MIA : LAX->SFO->MIA 
	 * 
	 * 		
	 */ 
	
	Vertex * jfk = new Vertex(0, "jfk");
	Vertex * ohare = new Vertex(1, "ohare");
	Vertex * lax = new Vertex(2, "lax");
	Vertex * sfo = new Vertex(5, "sfo");
	Vertex * mia = new Vertex(3, "mia");
	//adjacency vector of each airport
	std::vector<Vertex*> jfkAdj;
	std::vector<Vertex*> ohareAdj;
	std::vector<Vertex*> laxAdj;
	std::vector<Vertex*> sfoAdj;
	std::vector<Vertex*> miaAdj;

	//JFK adj 1/3
	jfkAdj.push_back(ohare);
	jfkAdj.push_back(sfo);
	jfkAdj.push_back(mia);

	//OHARE adj 1/3 
	ohareAdj.push_back(jfk);
	ohareAdj.push_back(sfo);
	ohareAdj.push_back(lax);

	//mia adj 1/2
	miaAdj.push_back(jfk);
	miaAdj.push_back(sfo);

	//sfo 1/4
	sfoAdj.push_back(lax);
	sfoAdj.push_back(ohare);
	sfoAdj.push_back(jfk);
	sfoAdj.push_back(mia);

	//lax 1/2
	laxAdj.push_back(ohare);
	laxAdj.push_back(sfo);

	//set adjacency
	jfk->setAdjacency(jfkAdj);
	ohare->setAdjacency(ohareAdj);
	lax->setAdjacency(laxAdj);
	sfo->setAdjacency(sfoAdj);
	mia->setAdjacency(miaAdj);

	
	//vector of all airport
	std::vector<Vertex*> airport;
	airport.push_back(jfk);
	airport.push_back(ohare);
	airport.push_back(lax);
	airport.push_back(sfo);
	airport.push_back(mia);

	BFS * graph = new BFS(airport);
	std::vector<Vertex*> sol = graph->fullTraversal(lax);
	std::vector<Vertex*> realSol;
	realSol.push_back(ohare);
	realSol.push_back(sfo);
	realSol.push_back(jfk);
	realSol.push_back(mia);


	delete graph;
	REQUIRE (sol == realSol);
}


TEST_CASE("Small Graph BFS traversal test") {
	//Small simple graph
	// a --- b---- c

	Vertex * a = new Vertex(1, "a");
	Vertex * b = new Vertex(2, "b");
	Vertex * c = new Vertex(3, "c");

	std::vector<Vertex*> aAdj;
	std::vector<Vertex*> bAdj;
	std::vector<Vertex*> cAdj;

	aAdj.push_back(b);
	
	bAdj.push_back(c);
	bAdj.push_back(a);

	cAdj.push_back(b);
	
	a->setAdjacency(aAdj);
	b->setAdjacency(bAdj);
	c->setAdjacency(cAdj);
	
	std::vector<Vertex*> nodes;
	nodes.push_back(a);
	nodes.push_back(b);
	nodes.push_back(c);

	BFS * graph = new BFS(nodes);
	std::vector<Vertex*> sol = graph->fullTraversal(a);

	std::vector<Vertex*> realSolution;
	realSolution.push_back(b);
	realSolution.push_back(c);

	delete graph;
	REQUIRE(sol == realSolution);
} 


