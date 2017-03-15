module AVLTree
( Tree(Null, Node)
, balanceFactor
, avlInsert
, avlRemove
, isBalanced
, content
, leftChild
, rightChild
, size
, height
, search
, findMin
, inorder
--, avlJoin
--, avlSplit
--, avlUnion
) where

import Tree

-- give it right then left subtrees
balanceFactor :: Tree a -> Tree a -> Int
balanceFactor a b = height b - height a

isBalanced Null = True
isBalanced (Node _ l r) = leftBalanced && rightBalanced && thisBalanced
    where leftBalanced = isBalanced l
          rightBalanced = isBalanced r
          thisBalanced = abs (balanceFactor l r) < 2

leftRotate (Node a l (Node b rl rr)) = (Node b (Node a l rl) rr)
rightRotate (Node a (Node b ll lr) r) = (Node b ll (Node a lr r))
leftRightRotate (Node a (Node b ll (Node c lrl lrr)) r) = (Node c (Node b ll lrl) (Node a lrr r))
rightLeftRotate (Node a l (Node b (Node c rll rlr) rr)) = (Node c (Node a l rll) (Node b rlr rr))

balance :: Tree a -> Tree a
balance Null = Null
balance (Node a l r)
    | b > 1 = fixRight (Node a l r)
    | b < -1 = fixLeft (Node a l r)
    | otherwise = Node a l r
    where b = balanceFactor l r

fixRight :: Tree a -> Tree a
fixRight Null = Null
fixRight (Node a l r)
    | br < 0 = rightLeftRotate (Node a l r)
    | otherwise = leftRotate (Node a l r)
    where br = balanceFactor (leftChild r) (rightChild r)

fixLeft :: Tree a -> Tree a
fixLeft Null = Null
fixLeft (Node a l r)
    | bl > 0 = leftRightRotate (Node a l r)
    | otherwise = rightRotate (Node a l r)
    where bl = balanceFactor (leftChild l) (rightChild l)

avlInsert :: (Ord a) => Tree a -> a -> Tree a
avlInsert Null a = Node a Null Null
avlInsert (Node c l r) a
    | c == a = Node c l r -- doesnt change anything
    | a < c = balance (Node c li r)
    | a > c = balance (Node c l ri)
    where li = avlInsert l a
          ri = avlInsert r a

avlRemove :: (Ord a) => Tree a -> a -> Tree a
avlRemove Null a = Null
avlRemove (Node c l r) a
    | a == c = case (l, r) of
                    (Null, Null) -> Null
                    (l, Null) -> l
                    (Null, r) -> r
                    (l, r) -> balance (Node rmin l rnew)
                        where rnew = avlRemove r rmin
                              rmin = findMin r
    | a < c = balance (Node c ld r)
    | a > c = balance (Node c l rd)
    where ld = avlRemove l a
          rd = avlRemove r a

-- avlJoin t1 t2 k, requires t2 > k > t1
--avlJoin :: Tree a -> Tree a -> a -> Tree a
--
--avlSplit :: Tree a -> a -> (Tree a, Tree a)
--
--avlUnion :: Tree a -> Tree a -> Tree a
