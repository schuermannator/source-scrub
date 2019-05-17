-- module main where

-- import qualified Data.ByteString.Lazy as L
-- numlines :: L.ByteString -> Int
numlines :: String -> Int
numlines content = length (lines content)

numlinefile :: FilePath -> IO Int
numlinefile path = do
  content <- readFile path
  return (numlines content)

main :: IO ()
main = do
  putStrLn "Running parser..."
  number <- numlinefile "data/test1.c"
  print number
