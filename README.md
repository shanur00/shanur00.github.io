# Linked List Reversal Visualization

## Initial State
```
head → [1] → [2] → [3] → [4] → NULL

node = NULL
currentNode = head (points to [1])
headNode = head (points to [1])
```

---

## Iteration 1
**Action:** `headNode = headNode->next`
```
headNode moves forward to [2]

head → [1] → [2] → [3] → [4] → NULL
       ↑     ↑
   current  headNode
```

**Action:** `currentNode->next = node`
```
[1] now points to NULL

NULL ← [1]   [2] → [3] → [4] → NULL
              ↑
           headNode
```

**Action:** `node = currentNode`, `currentNode = headNode`
```
node = NULL
currentNode = [1] (pointing to NULL now)
headNode = [2]

NULL ← [1]   [2] → [3] → [4] → NULL
       ↑     ↑
      node  current/head
```

---

## Iteration 2
**Action:** `headNode = headNode->next`
```
headNode moves forward to [3]

NULL ← [1]   [2] → [3] → [4] → NULL
       ↑     ↑    ↑
      node  current headNode
```

**Action:** `currentNode->next = node`
```
[2] now points to [1]

NULL ← [1] ← [2]   [3] → [4] → NULL
                    ↑
                 headNode
```

**Action:** `node = currentNode`, `currentNode = headNode`
```
NULL ← [1] ← [2]   [3] → [4] → NULL
             ↑     ↑
            node  current/head
```

---

## Iteration 3
**Action:** `headNode = headNode->next`
```
headNode moves forward to [4]

NULL ← [1] ← [2]   [3] → [4] → NULL
             ↑     ↑    ↑
            node  current headNode
```

**Action:** `currentNode->next = node`
```
[3] now points to [2]

NULL ← [1] ← [2] ← [3]   [4] → NULL
                          ↑
                       headNode
```

**Action:** `node = currentNode`, `currentNode = headNode`
```
NULL ← [1] ← [2] ← [3]   [4] → NULL
                   ↑     ↑
                  node  current/head
```

---

## Iteration 4
**Condition:** `headNode->next != NULL` is FALSE (headNode is at [4], next is NULL)

**Exit loop**

---

## After Loop
**Action:** `headNode->next = node`
```
[4] now points to [3]

NULL ← [1] ← [2] ← [3] ← [4]
                   ↑     ↑
                  node  headNode
```

**Action:** `head = headNode`
```
Final reversed list:

head → [4] → [3] → [2] → [1] → NULL
```

---
