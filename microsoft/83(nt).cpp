#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
// Alphabet size (# of symbols)
 
#define ALPHABET_SIZE (26)
#define INDEX(c) ((int)c - (int)'a')
 
#define FREE(p) \
    free(p);    \
    p = NULL;
 
// forward declration
 
// trie node
struct trie_node
{
    int value; // non zero if leaf
    trie_node *children[ALPHABET_SIZE];
};
 
// trie ADT
typedef struct trie trie;
 
struct trie
{
    trie_node *root;
    int count;
};
 
trie_node *getNode(void)
{
    trie_node *pNode = NULL;
 
    pNode = (trie_node *)malloc(sizeof(trie_node));
 
    if( pNode )
    {
        int i;
 
        pNode->value   = 0;
 
        for(i = 0; i < ALPHABET_SIZE; i++)
        {
            pNode->children[i] = NULL;
        }
    }
 
    return pNode;
}
 
void initialize(trie *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}
 
void insert(trie *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node *pCrawl;
 
    pTrie->count++;
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);
 
        if( pCrawl->children[index] )
        {
            // Skip current node
            pCrawl = pCrawl->children[index];
        }
        else
        {
            // Add new node
            pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
        }
    }
 
    // mark last node as leaf (non zero)
    pCrawl->value = pTrie->count;
}
 
int search(trie *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node *pCrawl;
 
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);
 
        if( !pCrawl->children[index] )
        {
            return 0;
        }
 
        pCrawl = pCrawl->children[index];
    }
 
    return (0 != pCrawl && pCrawl->value);
}
 
int leafNode(trie_node *pNode)
{
    return (pNode->value != 0);
}
 
int isItFreeNode(trie_node *pNode)
{
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++)
    {
        if( pNode->children[i] )
            return 0;
    }
 
    return 1;
}
 
bool deleteHelper(trie_node *pNode, char key[], int level, int len)
{
    if( pNode )
    {
        // Base case
        if( level == len )
        {
            if( pNode->value )
            {
                // Unmark leaf node
                pNode->value = 0;
 
                // If empty, node to be deleted
                if( isItFreeNode(pNode) )
                {
                    return true;
                }
 
                return false;
            }
        }
        else // Recursive case
        {
            int index = INDEX(key[level]);
 
            if( deleteHelper(pNode->children[index], key, level+1, len) )
            {
                // last node marked, delete it
                FREE(pNode->children[index]);
 
                // recursively climb up, and delete eligible nodes
                return ( !leafNode(pNode) && isItFreeNode(pNode) );
            }
        }
    }
 
    return false;
}
 
void deleteKey(trie *pTrie, char key[])
{
    int len = strlen(key);
 
    if( len > 0 )
    {
        deleteHelper(pTrie->root, key, 0, len);
    }
}
 
int main()
{
    char keys[][8] = {"she", "sells", "sea", "shore", "the", "by", "sheer"};
    trie trie;
 
    initialize(&trie);
 
    for(int i = 0; i < ARRAY_SIZE(keys); i++)
    {
        insert(&trie, keys[i]);
    }
    printf("%s %s\n", "she", search(&trie, "she") ? "Present in trie" : "Not present in trie");
    
    deleteKey(&trie, keys[0]);
 
    printf("%s %s\n", "she", search(&trie, "she") ? "Present in trie" : "Not present in trie");
 
    return 0;
}