
split sep str = splitHelp [] sep str

splitHelp :: [[Char]] -> Char -> [Char] -> [[Char]]
splitHelp res sep [] = res
splitHelp res sep (x:xs) = if x == sep
                              then 
