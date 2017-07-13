// Here Copy the codes implemented for 2 Sum
// Note: The returned array must be malloced, assume caller calls free().
// HashNode
typedef struct
{
    int mKey;
    // Value should be usd to store the count for the key
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
    int index = 0;
    for (; index < hashMap->mHashMapSize; index++)
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

void swap(int *nums, int numsSize, int i, int j)
{
    if (!nums || numsSize < 0 ||
        i < 0 || i > numsSize ||
        j < 0 || j > numsSize)
    {
        return;
    }

    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// Core logics for quick sort algorithm used to sort an array
int Partition(int *nums, int numsSize, int low, int high)
{
    int pivotKey = nums[low];

    while (low < high)
    {
        while (low < high && nums[high] >= pivotKey)
        {
            high--;
        }
        swap(nums, numsSize, low, high);

        while (low < high && nums[low] <= pivotKey)
        {
            low++;
        }
        swap(nums, numsSize, low, high);
    }

    return low;
}

void QuickSort(int *nums, int numsSize, int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = Partition(nums, numsSize, low, high);

        QuickSort(nums, numsSize, low, pivot - 1);
        QuickSort(nums, numsSize, pivot + 1, high);
    }
}

// TODO: Deal with the duplicates
void twoSum(int* nums, int lIndex, int rIndex, int target, int **result, int *resultCount)
{
    if (nums == NULL || rIndex <= lIndex || !result || !resultCount)
    {
        return;
    }

    HashMap * hashMap = NULL;
    HashNode * hashNode = NULL;

    // Construct a HashMap
    hashMap = hashMapConstruct(rIndex - lIndex + 1);
    if (hashMap == NULL)
    {
        return;
    }

    int diff = 0;
    int index = lIndex;
    for (; index <= rIndex; index++)
    {
        // Skip the duplicates
        while (nums[index] == nums[index + 1] && nums[index] + nums[index + 1] != target)
        {
            index++;
        }

        HashNode * tempNode = hashMapGetByKey(hashMap, nums[index]);
        if (tempNode != NULL && tempNode->mValue >= 2)
        {
            continue;
        }

        diff = target - nums[index];
        hashNode = hashMapGetByKey(hashMap, diff);

        if (hashNode != NULL)
        {
            int* resElem = (int *)malloc(sizeof(int) * 3);
            resElem[0] = -target;
            resElem[1] = diff;
            resElem[2] = nums[index];

            result[*resultCount] = resElem;
            (*resultCount)++;
        }

        if (tempNode == NULL)
        {
            hashMapSet(hashMap, nums[index], 1);
        }
        else
        {
            tempNode->mValue++;
        }
    }

    // Destroy the HashMap
    hashMapDestroy(hashMap);
}

// Return an array of arrays of size *returnSize.
// Note: The returned array must be malloced, assume caller calls free().
int** threeSum(int* nums, int numsSize, int* returnSize) {
    // Validations
    if (!nums || numsSize <= 2 || !returnSize)
    {
        return NULL;
    }

    // Sort the array
    QuickSort(nums, numsSize, 0, numsSize - 1);

    // Mallcate for result
    int maxSize = 4048;
    int** result = (int**)calloc(maxSize, sizeof(int*));

    // Traverse the sorted array and get array of result with 2 sum algorithm
    int resultCount = 0;
    int i = 0;
    for (; i < numsSize - 1; i++)
    {
        int twoSumTarget = -nums[i];

        twoSum(nums, i + 1, numsSize - 1, twoSumTarget, result, &resultCount);

        // Skip the duplicates
        while (nums[i] == nums[i + 1])
        {
            i++;
        }

    }

    *returnSize = resultCount;
    return result;
}