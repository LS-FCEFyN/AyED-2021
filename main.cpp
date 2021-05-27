#include <iostream>
#include <bits/stdc++.h>
#include "./queue.hxx"
#include "./stack.hxx"
#include "./narytree.hxx"

/*
 *
 *            N-Ary Tree (Left child, right sibling representation)
 *
 *          BINARY TREE (N = 2)
 *
 *            □ -> Root
 *           /           ( The box inmediatley under this is a child )
 *  Child <- □ - □       ( The box inmediatley to the right is a sibling )
 *          /
 *          □ - □ -> Sibling
 *
 *      From left to right we have the childs and the siblings
 *      Not the most efficient but it might just be "good enough"
 */

int main(int argc, char **argv) {
  /* Prevent compiler from complaining about un-used variables */
  (void)argc;
  (void)argv;
  /* --------------------------------------------------------- */

  /* Open file containing our text to be sorted in lexicographical order */
  std::fstream file;
  std::string fileName = "file.txt";

  file.open(fileName.c_str());
  /* ------------------------------------------------------------------- */

  /* Place holder variable where we will save our words */
  std::string word = "";
  /* -------------------------------------------------- */

  nary_tree<std::string> *tree = new nary_tree<std::string>("Hello");
  tree->addChild("World");
  tree->addSibling("!");
  tree->traverseTree();

  file.close(); /* Self explenatory, close the file before we exit the programm */
  return 0;
}
