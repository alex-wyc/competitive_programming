module Tree
( Tree(Null, Node)
, content
, leftChild
, rightChild
, size
, height
, search
, insert
, remove
, findMin
, findMax
) where

data Tree a = Null | Node { content :: a
                          , leftChild :: Tree a
                          , rightChild :: Tree a
                          }

instance Show a => Show (Tree a) where
    show Null = ""
    show (Node c l r) = "(" ++ show l ++ " " ++ show c ++ " " ++ show r ++ ")"

instance Eq a => Eq (Tree a) where
    Null == Null = True
    Null == Node _ _ _ = False
    Node _ _ _ == Null = False
    Node c1 l1 r1 == Node c2 l2 r2 = (c1 == c2) && (l1 == l2) && (r1 == r2)

size :: Tree a -> Int
size Null = 0
size tree = 1 + size (leftChild tree) + size (rightChild tree)

search :: (Ord a) => Tree a -> a -> Bool
search Null _ = False
search (Node c l r) a 
    | a == c = True
    | a > c = search r a
    | a < c = search l a

insert :: (Ord a) => a -> Tree a -> Tree a
insert a Null = Node a Null Null
insert a (Node c l r)
    | a < c = Node c (insert a l) r
    | a > c = Node c l (insert a r)
    | otherwise = Node c l r -- repeated will not be inserted

height :: Tree a -> Int
height Null = 0
height (Node _ l r) = 1 + max (height l) (height r)

findMax tree = if rightChild tree == Null then content tree else findMax $ rightChild tree

removeMax :: Tree a -> Tree a
removeMax (Node _ _ Null) = Null
removeMax (Node c l r) = Node c l $ removeMax r

findMin tree = if leftChild tree == Null then content tree else findMin $ leftChild tree

removeMin :: Tree a -> Tree a
removeMin (Node c Null _) = Null
removeMin (Node c l r) = Node c (removeMin l) r

remove :: (Ord a) => a -> Tree a -> Tree a
remove a Null = Null
remove a (Node c l r) = if a == c
                          then case (l, r) of
                              (Null, Null) -> Null -- leaf
                              (l, Null) -> l -- only left node
                              (Null, r) -> r -- only right node
                              (l, r) -> Node (findMax l) (removeMax l) r -- both
                          else if a < c
                                  then Node c (remove a l) r
                                  else Node c l (remove a r)
