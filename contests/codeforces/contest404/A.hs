import Control.Monad

getFaceCount name
    | name == "Tetrahedron" = 4
    | name == "Cube" = 6
    | name == "Octahedron" = 8
    | name == "Dodecahedron" = 12
    | name == "Icosahedron" = 20

main :: IO()
main = do
    w <- getLine
    s <- forM [1..(read w :: Int)] $ \i -> getLine
    print $ sum (map getFaceCount s)
