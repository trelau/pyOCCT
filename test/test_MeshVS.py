# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2021 Trevor Laughlin and the pyOCCT contributors
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
import unittest

from OCCT.MeshVS import MeshVS_Mesh, MeshVS_MeshEntityOwner, MeshVS_EntityType


class Test_MeshVS_MeshEntityOwner(unittest.TestCase):
    """
    Test for MeshVS_MeshEntityOwner class.
    """

    def test_MeshVS_MeshEntityOwner_Type(self):
        """
        Test that the mesh entity type works
        """
        mesh = MeshVS_Mesh()
        owner = MeshVS_MeshEntityOwner(mesh, 0, None, MeshVS_EntityType.MeshVS_ET_Node)
        self.assertEqual(owner.Type(), MeshVS_EntityType.MeshVS_ET_Node)


if __name__ == '__main__':
    unittest.main()
