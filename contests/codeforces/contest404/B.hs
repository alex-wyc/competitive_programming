{-# LANGUAGE BangPatterns #-}

import Control.Monad
import Data.List
import Data.Ord

sSpace w = span (/= ' ') w
toInt s = read s :: Int
toIntTup (a, b) = (toInt a, toInt b)

findMinMaxH :: Int -> Int -> Int -> IO((Int, Int))
findMinMaxH 0 minEnd maxStart = return (minEnd, maxStart)
findMinMaxH i !minEnd !maxStart = do -- sometimes lazy eval fucks you over
    w <- getLine
    let (start, end) = toIntTup $ sSpace w in
        findMinMaxH (i-1) (min minEnd end) (max maxStart start)

findMinMax :: Int -> IO((Int, Int))
findMinMax i = findMinMaxH i 10000000009 (-1)

main :: IO()
main = do
    chessCount <- getLine
    (cendmin, cstartmax) <- findMinMax $ toInt chessCount
    programCount <- getLine
    (pendmin, pstartmax) <- findMinMax $ toInt programCount
    print $ maximum [(pstartmax - cendmin), (cstartmax - pendmin), 0]
