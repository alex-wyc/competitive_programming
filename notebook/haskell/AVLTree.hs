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
) where

import Tree

-- give it right then left subtrees
balanceFactor :: Tree a -> Tree a -> Int
balanceFactor a b = height b - height a

isBalanced l r = (bf == 0 || bf == 1 || bf == -1) where bf = balanceFactor l r

leftRotate (Node a l (Node b rl rr)) = (Node b (Node a l rl) rr)
rightRotate (Node a (Node b ll lr) r) = (Node b ll (Node a lr r))
leftRightRotate (Node a (Node b ll (Node c lrl lrr)) r) = (Node c (Node b ll lrl) (Node a lrr r))
rightLeftRotate (Node a l (Node b (Node c rll rlr) rr)) = (Node c (Node a l rll) (Node b rlr rr))

avlInsert :: (Ord a) => Tree a -> a -> Tree a
avlInsert Null a = Node a Null Null
avlInsert (Node c l r) a
    | c == a = Node c l r -- doesnt change anything
    | a < c && balanceFactor li r == -2 && a < lc = rightRotate (Node c li r)
    | a < c && balanceFactor li r == -2 && a > lc = leftRightRotate (Node c li r)
    | a > c && balanceFactor l ri == 2 && a > rc = leftRotate (Node c l ri)
    | a > c && balanceFactor l ri == 2 && a < rc = rightLeftRotate (Node c l ri)
    | a < c = (Node c li r)
    | a > c = (Node c l ri)
    where li = avlInsert l a
          ri = avlInsert r a
          lc = content l
          rc = content r

avlRemove :: (Ord a) => Tree a -> a -> Tree a
avlRemove Null a = Null
avlRemove (Node c l r) a
    | a == c = case (l, r) of
                    (Null, Null) -> Null
                    (l, Null) -> l
                    (Null, r) -> r
                    (l, r) -> Node lmax lnew r
                        where lnew = avlRemove l lmax
                              lmax = findMax l
    | a < c && isBalanced ld r = Node c ld r
    | a < c && balanceFactor rl rr > 0 = leftRotate (Node c ld r)
    | a < c = rightLeftRotate (Node c ld r)
    | a > c && isBalanced l rd = Node c l rd
    | a > c && balanceFactor ll lr < 0 = rightRotate (Node c l rd)
    | a > c = leftRightRotate (Node c l rd)
    where ld = avlRemove l a
          rd = avlRemove r a
          ll = leftChild l
          lr = rightChild l
          rl = leftChild r
          rr = rightChild r
