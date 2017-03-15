import AVLTree

-- IO stuff

constructTree :: IO(Tree Int)
constructTree = build (Null)
    where build avlTree = do print avlTree
                             print $ isBalanced avlTree
                             word <- getLine
                             if word == ""
                                then return avlTree
                                else build $ avlInsert avlTree (read word :: Int)

deleteFromTree :: Tree Int -> IO(Tree Int)
deleteFromTree t = do print t
                      print $ isBalanced t
                      word <- getLine
                      if word == ""
                         then return t
                         else deleteFromTree (avlRemove t (read word :: Int))

searchInTree :: Tree Int -> IO()
searchInTree t = do word <- getLine
                    if word == ""
                       then putStrLn ""
                       else do
                           print $ search t (read word :: Int)
                           searchInTree t

main :: IO()
main = do
    test <- constructTree
    modifiedTest <- deleteFromTree test
    searchInTree modifiedTest
