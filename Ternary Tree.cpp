struct Node{
    char data;
    unsigned isEndOfString: 1;
    struct Node *left, *eq, *right;
};
struct Node* newNode(char data)
{
    struct Node* temp = (struct Node*) malloc(sizeof( struct Node ));
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = NULL;
    return temp;
}
void insert(struct Node** root, char *word)
{
	//Eerst nieuwe node aanmaken, indien die er niet is
    if (!(*root))
        *root = newNode(*word);
 
    // Als karakter kleiner is dan root char, links steken
    if ((*word) < (*root)->data)
        insert(&( (*root)->left ), word);
 
    // Als karakter groter is dan root char, rechts steken
    else if ((*word) > (*root)->data)
        insert(&( (*root)->right ), word);
 
    // Als current zelfde is als root char
    else
    {
		//Karakter zit er al in, steek volgende karakter erin
        if (*(word+1))
            insert(&( (*root)->eq ), word+1);
 
        //Als er geen volgend karakter is, zijn we op het einde
        else
            (*root)->isEndOfString = 1;
    }
}
 
// Function to search a given word in TST
int searchTST(struct Node *root, char *word)
{
    if (*word < (root)->data)
        return searchTST(root->left, word);
 
    else if (*word > (root)->data)
        return searchTST(root->right, word);
 
    else
    {
        if (*(word+1) == '\0')
            return root->isEndOfString;
        return searchTST(root->eq, word+1);
    }
}

void traverseTSTUtil(struct Node* root, char* buffer, int depth)
{
    if (root)
    {
        // First traverse the left subtree
        traverseTSTUtil(root->left, buffer, depth);

        // Store the character of this node
        buffer[depth] = root->data;
        if (root->isEndOfString)
        {
            buffer[depth+1] = '\0';
            printf( "%s\n", buffer);
        }
 
        // Traverse the subtree using equal pointer (middle subtree)
        traverseTSTUtil(root->eq, buffer, depth + 1);
 
        // Finally Traverse the right subtree
        traverseTSTUtil(root->right, buffer, depth);
    }
}