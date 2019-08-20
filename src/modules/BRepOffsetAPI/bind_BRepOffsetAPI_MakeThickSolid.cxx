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
#include <BRepOffsetAPI_MakeOffsetShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepOffset_Mode.hxx>
#include <GeomAbs_JoinType.hxx>
#include <BRepOffsetAPI_MakeThickSolid.hxx>

void bind_BRepOffsetAPI_MakeThickSolid(py::module &mod){

py::class_<BRepOffsetAPI_MakeThickSolid, std::unique_ptr<BRepOffsetAPI_MakeThickSolid>, BRepOffsetAPI_MakeOffsetShape> cls_BRepOffsetAPI_MakeThickSolid(mod, "BRepOffsetAPI_MakeThickSolid", "Describes functions to build hollowed solids. A hollowed solid is built from an initial solid and a set of faces on this solid, which are to be removed. The remaining faces of the solid become the walls of the hollowed solid, their thickness defined at the time of construction. the solid is built from an initial solid <S> and a set of faces {Fi} from <S>, builds a solid composed by two shells closed by the {Fi}. First shell <SS> is composed by all the faces of <S> expected {Fi}. Second shell is the offset shell of <SS>. A MakeThickSolid object provides a framework for: - defining the cross-section of a hollowed solid, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<>());
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"));
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode>(), py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"));
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean>(), py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"));
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"));
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType>(), py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"));
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("RemoveIntEdges"));

// Fields

// Methods
// cls_BRepOffsetAPI_MakeThickSolid.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakeThickSolid::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeThickSolid.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakeThickSolid::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeThickSolid.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakeThickSolid::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeThickSolid.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakeThickSolid::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeThickSolid.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakeThickSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeThickSolid.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakeThickSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidBySimple", (void (BRepOffsetAPI_MakeThickSolid::*)(const TopoDS_Shape &, const Standard_Real)) &BRepOffsetAPI_MakeThickSolid::MakeThickSolidBySimple, "Constructs solid using simple algorithm. According to its nature it is not possible to set list of the closing faces. This algorithm does not support faces removing. It is caused by fact that intersections are not computed during offset creation. Non-closed shell or face is expected as input.", py::arg("theS"), py::arg("theOffsetValue"));
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidByJoin", [](BRepOffsetAPI_MakeThickSolid &self, const TopoDS_Shape & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.MakeThickSolidByJoin(a0, a1, a2, a3); });
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidByJoin", [](BRepOffsetAPI_MakeThickSolid &self, const TopoDS_Shape & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Real a3, const BRepOffset_Mode a4) -> void { return self.MakeThickSolidByJoin(a0, a1, a2, a3, a4); });
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidByJoin", [](BRepOffsetAPI_MakeThickSolid &self, const TopoDS_Shape & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Real a3, const BRepOffset_Mode a4, const Standard_Boolean a5) -> void { return self.MakeThickSolidByJoin(a0, a1, a2, a3, a4, a5); });
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidByJoin", [](BRepOffsetAPI_MakeThickSolid &self, const TopoDS_Shape & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Real a3, const BRepOffset_Mode a4, const Standard_Boolean a5, const Standard_Boolean a6) -> void { return self.MakeThickSolidByJoin(a0, a1, a2, a3, a4, a5, a6); });
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidByJoin", [](BRepOffsetAPI_MakeThickSolid &self, const TopoDS_Shape & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Real a3, const BRepOffset_Mode a4, const Standard_Boolean a5, const Standard_Boolean a6, const GeomAbs_JoinType a7) -> void { return self.MakeThickSolidByJoin(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidByJoin", (void (BRepOffsetAPI_MakeThickSolid::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean)) &BRepOffsetAPI_MakeThickSolid::MakeThickSolidByJoin, "Constructs a hollowed solid from the solid S by removing the set of faces ClosingFaces from S, where: Offset defines the thickness of the walls. Its sign indicates which side of the surface of the solid the hollowed shape is built on; - Tol defines the tolerance criterion for coincidence in generated shapes; - Mode defines the construction type of parallels applied to free edges of shape S. Currently, only one construction type is implemented, namely the one where the free edges do not generate parallels; this corresponds to the default value BRepOffset_Skin; Intersection specifies how the algorithm must work in order to limit the parallels to two adjacent shapes: - if Intersection is false (default value), the intersection is calculated with the parallels to the two adjacent shapes, - if Intersection is true, the intersection is calculated by taking account of all parallels generated; this computation method is more general as it avoids self-intersections generated in the offset shape from features of small dimensions on shape S, however this method has not been completely implemented and therefore is not recommended for use; - SelfInter tells the algorithm whether a computation to eliminate self-intersections needs to be applied to the resulting shape. However, as this functionality is not yet implemented, you should use the default value (false); - Join defines how to fill the holes that may appear between parallels to the two adjacent faces. It may take values GeomAbs_Arc or GeomAbs_Intersection: - if Join is equal to GeomAbs_Arc, then pipes are generated between two free edges of two adjacent parallels, and spheres are generated on 'images' of vertices; it is the default value, - if Join is equal to GeomAbs_Intersection, then the parallels to the two adjacent faces are enlarged and intersected, so that there are no free edges on parallels to faces. RemoveIntEdges flag defines whether to remove the INTERNAL edges from the result or not. Warnings Since the algorithm of MakeThickSolid is based on MakeOffsetShape algorithm, the warnings are the same as for MakeOffsetShape.", py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("RemoveIntEdges"));
cls_BRepOffsetAPI_MakeThickSolid.def("Build", (void (BRepOffsetAPI_MakeThickSolid::*)()) &BRepOffsetAPI_MakeThickSolid::Build, "None");
cls_BRepOffsetAPI_MakeThickSolid.def("Modified", (const TopTools_ListOfShape & (BRepOffsetAPI_MakeThickSolid::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakeThickSolid::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));

// Enums

}