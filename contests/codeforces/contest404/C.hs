sSpace w = span (/= ' ') w
toInt s = read s :: Integer
toIntTup (a, b) = (toInt a, toInt b)

solve :: Integer -> Integer -> Integer
solve n m
    | n <= m = n
    | otherwise = ceiling ((-1 + sqrt(1 + 8 * (fromIntegral (n - m)))) / 2) + m

main :: IO()
main = do
    input <- getLine
    let (n, m) = toIntTup $ sSpace input  in
        print $ solve n m
