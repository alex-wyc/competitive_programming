import Data.Maybe
import Data.Map (Map)
import qualified Data.Map as Map
import Control.Monad

data Trie a = Trie { wordCount :: Int
                   , prefixCount :: Int
                   , children :: Map a (Trie a)
                   }

size t = prefixCount t -- size is prefix count of root

insert :: (Ord a) => [a] -> Trie a -> Trie a -- inserts string into trie
insert [] (Trie i j m) = Trie (i + 1) (j + 1) m
insert (x:xs) (Trie i j m) = Trie i (j + 1) $ Map.insert x updatedChild m
    where updatedChild = insert xs child
          child = Map.findWithDefault def x m
          def = Trie 0 0 Map.empty

removeH :: (Ord a) => [a] -> Trie a -> Maybe (Trie a) -- removes string from trie, if empty return Nothing
removeH [] (Trie 1 j m)
    | j == 0 = Nothing -- no other thing with this prefix, this is a leaf
    | otherwise = Just (Trie 0 (j - 1) m)
removeH [] (Trie i j m)
    | i == 0 = Just (Trie i j m) -- this word is not in the dictionary
    | i == 1 && j == 1 = Nothing -- this is one word, no further relations
    | otherwise = Just (Trie (i - 1) (j - 1) m)
removeH (x:xs) (Trie i j m)
    | i == 0 && Map.size updatedM == 0 = Nothing
    | otherwise = Just (Trie i (Map.fold foo i updatedM) updatedM) -- O(N) re-compute j... perhaps not optimal
    where foo a b = b + (prefixCount a)
          updatedM = Map.update (removeH xs) x m

remove str t = fromMaybe (Trie 0 0 Map.empty) (removeH str t)

countPrefix :: (Ord a) => [a] -> Trie a -> Int
countPrefix [] (Trie i j m) = j
countPrefix (x:xs) (Trie i j m) = maybe 0 (countPrefix xs) (Map.lookup x m)

member :: (Ord a) => [a] -> Trie a -> Bool
member [] (Trie i j m) = (i > 0)
member (x:xs) (Trie i j m) = maybe False (member xs) (Map.lookup x m)

-- I/O and main thread stuff

buildTrieFromInput :: IO (Trie Char)
buildTrieFromInput = go (Trie 0 0 Map.empty)
    where go trie = do word <- getLine
                       if word == ""
                           then return trie
                           else go (insert word trie)

queryResults :: (Trie Char) -> IO()
queryResults t = do query <- getLine
                    unless (query == "") $ do
                        putStrLn $ show $ countPrefix query t
                        queryResults t


deleteFromTrie :: (Trie Char) -> IO (Trie Char)
deleteFromTrie t = do
    word <- getLine
    if word == ""
       then return t
       else deleteFromTrie (remove word t)

main :: IO()
main = do builtTrie <- buildTrieFromInput
          queryResults builtTrie
          updatedTrie <- deleteFromTrie builtTrie
          queryResults updatedTrie
