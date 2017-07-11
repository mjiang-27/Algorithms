/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
 // HashNode
typedef struct
{
    int mKey;
    int mValue;
} HashNode;

typedef struct
{
    int mHashMapSize;
    // Array pointer for HashNode pointer
    HashNode **mVectors;
} HashMap;

//////////////////////////////////////////////////////
// Operations on HashMap
//////////////////////////////////////////////////////
HashMap * hashMapConstruct(int hashMapSize)
{
    // Malloc for HashMap
    HashMap *hashMap = (HashMap *)(malloc(sizeof(HashMap)));
    
    // Assign for struct members
    hashMap->mHashMapSize = hashMapSize;
    hashMap->mVectors = (HashNode **)calloc(hashMapSize, sizeof(HashNode *));
    
    return hashMap;
}
void hashMapDestroy(HashMap * hashMap)
{
    // Free each dynamic pointer in each hash node
    HashNode *node = NULL;
    for (int index = 0; index < hashMap->mHashMapSize; index++)
    {
        node = hashMap->mVectors[index];
        if (node != NULL)
        {
            free(node);
            node = NULL;
        }
    }
    
    // free dynamic pointer in hash map
    free(hashMap->mVectors);
    free(hashMap);
}

// Set Hash Map with given key-value pair, starting from the position abs(key % (hashMap->size))
// Fixed size for HashMap here.
// TODO: make Hash Map change the size dynamically
void hashMapSet(HashMap *hashMap, int key, int value)
{
    int mode = abs(key % (hashMap->mHashMapSize));
    HashNode * newNode = NULL;
    
    while ((newNode = hashMap->mVectors[mode]) != NULL)
    {
        if (mode < hashMap->mHashMapSize - 1)
        {
            mode++;
        }
        else
        {
            mode = 0;
        }
    }
    
    // Malloc for the new Hash Node
    newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->mKey = key;
    newNode->mValue = value;
    
    // Add new Hash Node into Hash Map
    hashMap->mVectors[mode] = newNode;
}

HashNode *hashMapGetByKey(HashMap *hashMap, int key)
{
    int mode = abs(key % (hashMap->mHashMapSize));
    HashNode * newNode = NULL;
    
    while ((newNode = hashMap->mVectors[mode]) != NULL)
    {
        if (newNode->mKey == key)
        {
            return newNode;
        }
        
        if (mode < hashMap->mHashMapSize - 1)
        {
            mode++;
        }
        else
        {
            mode = 0;
        }
    }
    
    return NULL;
}

int* twoSum(int* nums, int numsSize, int target)
{
    if (nums == NULL || numsSize <= 0)
    {
        return NULL;
    }
    
    HashMap * hashMap = NULL;
    HashNode * hashNode = NULL;
    
    // Construct a HashMap
    hashMap = hashMapConstruct(numsSize);
    if (hashMap == NULL)
    {
        return NULL;
    }
    
    int diff = 0;
    for (int index = 0; index < numsSize; index++)
    {
        diff = target - nums[index];
        hashNode = hashMapGetByKey(hashMap, diff);
        
        if (hashNode != NULL)
        {
            int* result = malloc(sizeof(int)*2);
            result[0] = hashNode->mValue;
            result[1] = index;
            
            // Destroy the HashMap
            hashMapDestroy(hashMap);
            
            return result;
        }
        else
        {
            hashMapSet(hashMap, nums[index], index);
        }
    }
    
    return NULL;
}