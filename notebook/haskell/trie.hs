import Data.Maybe
import Data.Map (Map)
import qualified Data.Map as Map
import Control.Monad

data Trie a = Trie Int (Map a (Trie a))

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

countPrefix :: (Ord a) => [a] -> Trie a -> Int
countPrefix [] (Trie i m)
    | Map.size m == 0   = i
    | otherwise         = i + Map.fold scf 0 m
        where scf a b = b + (countPrefix [] a)
countPrefix (x:xs) (Trie i m) = maybe 0 (countPrefix xs) (Map.lookup x m)

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

main :: IO()
main = do builtTrie <- buildTrieFromInput
          queryResults builtTrie
