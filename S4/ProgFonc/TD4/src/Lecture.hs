module Lecture (Lecture, lctrLenght, lctrRoom, lctrStart, lctrTeacher, lctrYear) where

import Classroom (Classroom)
import Teacher (Teacher)

data Lecture = Lecture {lctrTeacher :: Teacher, lctrYear :: Int, lctrRoom :: Classroom, lctrStart :: Int, lctrLenght :: Int}
  deriving (Show, Eq)