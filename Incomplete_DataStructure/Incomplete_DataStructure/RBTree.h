#pragma once
#include "Main.h"

enum Color
{
    RED,
    BLACK
};

class Node
{
public:
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    Color color = BLACK;
};

class RBTree
{

};