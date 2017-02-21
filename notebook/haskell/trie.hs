import Data.Maybe
import Data.Map (Map)
import qualified Data.Map as Map
import Control.Monad

data Trie a = Null | Trie Int (Map a (Trie a))

size :: Trie a -> Int -- number of words / arrays stores in the trie
size (Trie i m)
    | Map.size m == 0   = i
    | otherwise         = i + Map.fold ss 0 m
        where ss a b = b + (size a)

insert :: (Ord a) => [a] -> Trie a -> Trie a -- inserts an array into trie
insert [] (Trie i m) = Trie (i + 1) m
insert (x:xs) (Trie i m) = Trie i $ Map.insert x updatedChild m
    where updatedChild = insert xs child
          child = Map.findWithDefault def x m
          def = Trie 0 Map.empty

removeH :: (Ord a) => [a] -> Trie a -> Maybe (Trie a)
removeH [] (Trie 1 m) = if Map.size m == 0
    then Nothing
    else Just (Trie 0 m)
removeH [] (Trie i m)
    | i == 0 = Just (Trie i m) -- word not in the trie
    | i == 1 && Map.size m == 0 = Nothing -- this is a leaf, we delete
    | otherwise = Just (Trie (i - 1) m)
removeH (x:xs) (Trie i m)
    | i == 0 && Map.size updatedM == 0 = Nothing
    | otherwise = Just (Trie i updatedM)
    where updatedM = Map.update (removeH xs) x m

remove str t = fromMaybe (Trie 0 Map.empty) (removeH str t)

countPrefix :: (Ord a) => [a] -> Trie a -> Int
countPrefix [] (Trie i m)
    | Map.size m == 0   = i
    | otherwise         = i + Map.fold scf 0 m
        where scf a b = b + (countPrefix [] a)
countPrefix (x:xs) (Trie i m) = maybe 0 (countPrefix xs) (Map.lookup x m)

member :: (Ord a) => [a] -> Trie a -> Bool
member [] (Trie i m) = (i > 0)
member (x:xs) (Trie i m) = maybe False (member xs) (Map.lookup x m)

-- I/O and main thread stuff

buildTrieFromInput :: IO (Trie Char)
buildTrieFromInput = go (Trie 0 Map.empty)
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
