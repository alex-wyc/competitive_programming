import qualified Data.Set as Set

main :: IO()
main = do
    word <- getLine
    let size = (read word :: Int)
        test = foldl (\set el -> Set.insert el set) (Set.empty) [1..size] in
        print $ map (\el -> Set.member el test) [1..(2*size)]
