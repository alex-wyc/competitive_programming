import Control.Monad
import Data.List
import Data.Ord

getMaxDist :: [(Int, Int)] -> [(Int, Int)] -> Int
getMaxDist chess program = maximum [(lbc - eep), (lbp - eec), 0]
    where earliestEnd lst = snd . head $ sortBy (comparing snd) lst
          eec = earliestEnd chess
          eep = earliestEnd program
          latestBegin lst = fst . head $ sortBy (comparing (Down . fst)) lst
          lbc = latestBegin chess
          lbp = latestBegin program

sSpace w = span (/= ' ') w
toInt s = read s :: Int
toIntTup (a, b) = (toInt a, toInt b)

buildArrWith :: Int -> [(Int, Int)] -> IO([(Int, Int)])
buildArrWith 0 lst = return lst
buildArrWith i lst = do
    w <- getLine
    buildArrWith (i-1) ((toIntTup $ sSpace w):lst)

buildArr :: Int -> IO([(Int, Int)])
buildArr n = buildArrWith n []

main :: IO()
main = do
    chessCount <- getLine
    chessTimes <- buildArr $ toInt chessCount
    programCount <- getLine
    programTimes <- buildArr $ toInt programCount
    print $ getMaxDist chessTimes programTimes
