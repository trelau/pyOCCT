import unittest

from OCCT.TopoDS import TopoDS_Shape, TopoDS_ListOfShape


class TestNCollectionList(unittest.TestCase):
    """
    Test for NCollection_List template
    """

    def test_iter(self):
        """
        Test __iter__ method.
        """
        s1 = TopoDS_Shape()
        s2 = TopoDS_Shape()
        s3 = TopoDS_Shape()
        shape_list = TopoDS_ListOfShape()
        shape_list.Append(s1)
        shape_list.Append(s2)
        shape_list.Append(s3)
        self.assertEqual(shape_list.Size(), 3)
        for s in shape_list:
            self.assertIsInstance(s, TopoDS_Shape)


if __name__ == '__main__':
    unittest.main()
