#include <iostream>
#include "binarytree.h"
using namespace std;

int main()
{
    BinaryTree tree;

    cout << "Inserting nodes...";
    tree.insertNode(5);
    tree.insertNode(8);
    tree.insertNode(3);
    tree.insertNode(12);
    tree.insertNode(9);
    tree.insertNode(21);
    tree.insertNode(1);
    cout << " Done.\n";

    cout << "\n==================================" << endl
    << "           Display                  " << endl
    << "====================================" << endl;

    cout << "Highest to lowest: ";
    tree.displayHiToLow();
    cout << endl;
    /*
    cout << "Inorder:  ";
    tree.displayInOrder() << endl;
    cout << endl << "Postorder:";
    tree.displayPostOrder();
    cout << endl << "Preorder: ";
    tree.displayPreOrder();
    */
    cout << endl;

    cout << "\n==================================" << endl
    << "           Depth Check                 " << endl
    << "====================================" << endl;
    cout << "Depth for 21 = " << tree.depth(21,0) << endl;
    cout << "Depth for 8 = " << tree.depth(8,0) << endl;
    cout << "Depth for 12 = " << tree.depth(12,0) << endl;
    cout << "Depth for 9 = " << tree.depth(9,0) << endl;
    cout << "Depth for 1 = " << tree.depth(1,0) << endl;
    cout << "Depth for 3 = " << tree.depth(3,0) << endl;
    cout << "Depth for 5 = " << tree.depth(5,0) << endl;

    cout << "\n==================================" << endl
    << "           Max Path and Balance            " << endl
    << "====================================" << endl;
    cout << "Sum of max path = " << tree.findMax() << endl;
    cout << "Is the tree balanced...";
    tree.balanceCheck();

    cout << "\n==================================" << endl
    << "           Search and Delete                 " << endl
    << "====================================" << endl;

    tree.displayInOrder();
    cout << "\nSearching for 1...";
    if (tree.searchNode(1) == true)
        cout << "found it.\n";

    cout << "Deleting 1...";
    tree.remove(1);
    cout << "done.\n";

    tree.displayInOrder();
    cout << endl;

    cout << "Searching for 1...";
    if (tree.searchNode(1) == false)
        cout << "couldn't find it.\n";

    return 0;
}
