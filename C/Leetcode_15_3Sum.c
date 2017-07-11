// Here Copy the codes implemented for 2 Sum
// Note: The returned array must be malloced, assume caller calls free().
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
		
		while (low < high && nums[low] <= pivotKey)) 
		{
			low++;
		}
		swap(nums, numsSize, low, high);
	}
	
	return low;
}

void QuikSort(int *nums, int numsSize, int low, int high) 
{
	if (!nums || numsSize <= 0 || low > high) 
	{
		return;
	}

	int pivot;
	
	pivot = Partition(nums, numsSize, low, high);
		
	QuickSort(nums, numsSize, low, pivot - 1);
	QuickSort(nums, numsSize, pivot, high);
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
	QuikSort(nums, numsSize, 0, numsSize - 1);
	
	// Traverse the sorted array and get array of result with 2 sum algorithm
	int twoSumTarget;
	for (int i = 0; i < numsSize; i++) 
	{
		twoSumTarget = -nums[i];
		
		// TODO
	}
}