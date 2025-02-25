/*
 * File: WikiTree.cpp
 * --------------------------------
 * Impplementation for the WikiTree class.
 * Code is self-documenting.  Implementation notes are minimal.
 */

#include "WikiTree.h"
#include "cpr/cpr.h"
#include <queue>
#include <iostream>
#include "parser.h"

WikiTree::WikiTree(Vertex *croot){
     root = croot;
     vertexList.push_back(root);
}

Vertex * WikiTree::getRoot() const {
    return root;
}


void WikiTree::addEdge(Vertex *cparent, Vertex *cchild){
    cchild->setParent(cparent);
    vertexList.push_back(cchild);

}

/*
 * Function: buildWikiTree
 * ------------------------
 * Implementation Notes: Builds a WikiTree with the root member variable as the root of the tree.
 * Function uses the Parser class to initialize Parser objects and identify additional wikipedia page links inside the paragraph sections
 * of the the html file for each Vertex key (a url of a Wikipedia page).  These links are identified as the children of the Vertex and
 * added to the tree in a breadth first search style approach.
 * The searchigng continues until stopUrl has been found on the html page of a Vertex.
 * Function return a Vertex with stopUrl as its key.  If the breadth first search finishse before stopUrl is found, the root is returned.
 * The root returning is highly unlikely given the scope of Wikipedia.
 *
 * The function also prints the key values (Wikipedia page urls) for all Vertices added to the WikiTree.
 */
Vertex * WikiTree::buildWikiTree(const std::string & stopUrl){
    std::queue<Vertex *> wikiQueue;
    root->setColor("gray");
    root->setDistance(0);
    wikiQueue.push(root);

    while(!wikiQueue.empty()) {
        Vertex * u = wikiQueue.front();
        wikiQueue.pop();
        Parser p (u);
        std::vector<std::string> pageLinks = p.searchWikiPage();
        for (std::string page : pageLinks) {
            Vertex *v = new Vertex(page, u, "gray");
            v->setDistance(u->getDistance() + 1);
            wikiQueue.push(v);
            vertexList.push_back(v);
            if (page == stopUrl) {
                return v;
            }
        }
        u->setColor("black");

    }
    return root;
}

WikiTree::~WikiTree(){
    for (Vertex *v : vertexList){
        delete v;
    }
}


