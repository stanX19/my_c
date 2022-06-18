#include <stdlib.h>
#define END_NODE_VAL (-1002)
#define NULL_NODE_VAL (-1001)
#define MAX_QUEUE (30000)

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    int head;
    int tail;
    struct TreeNode* queue[MAX_QUEUE];
} queue_t;

static void queue_init(queue_t* queue)
{
    assert(queue);
    
    queue->head = 0;
    queue->tail = 0;
}

static bool queue_is_empty(queue_t* queue)
{
    assert(queue);
    return queue->head == queue->tail;
}

static void queue_insert(queue_t* queue, struct TreeNode* node)
{
    assert(queue);
    
    // no-op in case queue is full. this is a design decision.
    if (queue->tail == MAX_QUEUE) {
        return;
    }
    
    queue->queue[queue->tail] = node;
    queue->tail++;
}

static struct TreeNode* queue_remove(queue_t* queue)
{
    assert(queue);
    
    struct TreeNode* const tmp = queue->queue[queue->head];
    queue->head++;
    
    // reset queue if it's now empty
    if (queue->head == queue->tail) {
        queue->head = 0;
        queue->tail = 0;
    }
    
    return tmp;
}

/** Encodes a tree to a single string. */
int* serialize(struct TreeNode* root)
{
    if (!root) {
        return NULL;
    }
    
    queue_t queue;
    queue_init(&queue);
    
    // XXX: just to avoid realloc this array
    int* serialized = malloc(MAX_QUEUE * sizeof(int));
    assert(serialized);
    int current = 0;
    
    queue_insert(&queue, root);
    
    while(!queue_is_empty(&queue)) {
        struct TreeNode* node = queue_remove(&queue);
        
        if (node) {
            serialized[current] = node->val;
            
            queue_insert(&queue, node->left);
            queue_insert(&queue, node->right);
        } else {
            serialized[current] = NULL_NODE_VAL;
        }
        
        current++;
    }
    
    serialized[current] = END_NODE_VAL;
    
    return serialized;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(int* data)
{
    if (!data) {
        return NULL;
    }
    
    queue_t queue;
    queue_init(&queue);
    
    
    const int first = data[0];
    if (first == NULL_NODE_VAL) {
        return NULL;
    }
    
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = first;
    
    queue_insert(&queue, root);
    int current = 1;
    
    while (!queue_is_empty(&queue) && data[current] != END_NODE_VAL) {
        struct TreeNode* node = queue_remove(&queue);
        node->left = NULL;
        node->right = NULL;
        
        const int left_value = data[current++];
        const int right_value = data[current++];
        
        if (left_value != NULL_NODE_VAL) {
            node->left = malloc(sizeof(struct TreeNode));
            node->left->val = left_value;
            
            queue_insert(&queue, node->left);
        }
        
        if (right_value != NULL_NODE_VAL) {
            node->right = malloc(sizeof(struct TreeNode));
            node->right->val = right_value;
            
            queue_insert(&queue, node->right);
        }
    }
    
    return root;
}
