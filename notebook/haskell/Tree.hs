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
, inorder
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

inorder Null = []
inorder (Node c l r) = (inorder l) ++ [c] ++ (inorder r)

findMin = head . inorder

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

remove :: (Ord a) => Tree a -> a -> Tree a
remove Null a = Null
remove (Node c l r) a = if a == c
                          then case (l, r) of
                              (Null, Null) -> Null -- leaf
                              (l, Null) -> l -- only left node
                              (Null, r) -> r -- only right node
                              (l, r) -> Node rmin l rnew -- both
                                  where rnew = remove r rmin
                                        rmin = findMin r
                          else if a < c
                                  then Node c (remove l a) r
                                  else Node c l (remove r a)
