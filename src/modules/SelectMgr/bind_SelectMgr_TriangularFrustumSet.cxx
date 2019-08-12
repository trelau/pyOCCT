/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <SelectMgr_BaseFrustum.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_GTrsf.hxx>
#include <SelectMgr_VectorTypes.hxx>
#include <gp_Pnt.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Select3D_TypeOfSensitivity.hxx>
#include <NCollection_Vector.hxx>
#include <SelectMgr_TriangularFrustumSet.hxx>

void bind_SelectMgr_TriangularFrustumSet(py::module &mod){

py::class_<SelectMgr_TriangularFrustumSet, opencascade::handle<SelectMgr_TriangularFrustumSet>, SelectMgr_BaseFrustum> cls_SelectMgr_TriangularFrustumSet(mod, "SelectMgr_TriangularFrustumSet", "This class is used to handle polyline selection. The main principle of polyline selection algorithm is to split the polygon defined by polyline onto triangles. Than each of them is considered as a base for triangular frustum building. In other words, each triangle vertiex will be projected from 2d screen space to 3d world space onto near and far view frustum planes. Thus, the projected triangles make up the bases of selecting frustum. When the set of such frustums is created, the function determining selection iterates through triangular frustum set and searches for overlap with any frustum.");

// Constructors
cls_SelectMgr_TriangularFrustumSet.def(py::init<>());

// Fields

// Methods
cls_SelectMgr_TriangularFrustumSet.def("Build", (void (SelectMgr_TriangularFrustumSet::*)(const TColgp_Array1OfPnt2d &)) &SelectMgr_TriangularFrustumSet::Build, "Meshes polygon bounded by polyline. Than organizes a set of triangular frustums, where each triangle's projection onto near and far view frustum planes is considered as a frustum base", py::arg("thePoints"));
cls_SelectMgr_TriangularFrustumSet.def("ScaleAndTransform", (opencascade::handle<SelectMgr_BaseFrustum> (SelectMgr_TriangularFrustumSet::*)(const Standard_Integer, const gp_GTrsf &) const) &SelectMgr_TriangularFrustumSet::ScaleAndTransform, "Returns a copy of the frustum with all sub-volumes transformed according to the matrix given", py::arg("theScale"), py::arg("theTrsf"));
cls_SelectMgr_TriangularFrustumSet.def("Overlaps", [](SelectMgr_TriangularFrustumSet &self, const SelectMgr_Vec3 & theMinPnt, const SelectMgr_Vec3 & theMaxPnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theMinPnt, theMaxPnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "None", py::arg("theMinPnt"), py::arg("theMaxPnt"), py::arg("theDepth"));
cls_SelectMgr_TriangularFrustumSet.def("Overlaps", [](SelectMgr_TriangularFrustumSet &self, const SelectMgr_Vec3 & theMinPnt, const SelectMgr_Vec3 & theMaxPnt, Standard_Boolean * theInside){ Standard_Boolean rv = self.Overlaps(theMinPnt, theMaxPnt, theInside); return std::tuple<Standard_Boolean, Standard_Boolean *>(rv, theInside); }, "None", py::arg("theMinPnt"), py::arg("theMaxPnt"), py::arg("theInside"));
cls_SelectMgr_TriangularFrustumSet.def("Overlaps", [](SelectMgr_TriangularFrustumSet &self, const gp_Pnt & thePnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "None", py::arg("thePnt"), py::arg("theDepth"));
cls_SelectMgr_TriangularFrustumSet.def("Overlaps", [](SelectMgr_TriangularFrustumSet &self, const TColgp_Array1OfPnt & theArrayOfPnts, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPnts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "None", py::arg("theArrayOfPnts"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectMgr_TriangularFrustumSet.def("Overlaps", [](SelectMgr_TriangularFrustumSet &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "None", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("theDepth"));
cls_SelectMgr_TriangularFrustumSet.def("Overlaps", [](SelectMgr_TriangularFrustumSet &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, const gp_Pnt & thePnt3, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, thePnt3, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "None", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("thePnt3"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectMgr_TriangularFrustumSet.def("GetPlanes", (void (SelectMgr_TriangularFrustumSet::*)(NCollection_Vector<SelectMgr_Vec4> &) const) &SelectMgr_TriangularFrustumSet::GetPlanes, "Stores plane equation coefficients (in the following form: Ax + By + Cz + D = 0) to the given vector", py::arg("thePlaneEquations"));

// Enums

}