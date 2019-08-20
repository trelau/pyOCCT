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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepOffset_Mode.hxx>
#include <GeomAbs_JoinType.hxx>
#include <BRepOffset_MakeOffset.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepOffsetAPI_MakeOffsetShape.hxx>
#include <BRepOffset_MakeSimpleOffset.hxx>

void bind_BRepOffsetAPI_MakeOffsetShape(py::module &mod){

py::class_<BRepOffsetAPI_MakeOffsetShape, std::unique_ptr<BRepOffsetAPI_MakeOffsetShape>, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_MakeOffsetShape(mod, "BRepOffsetAPI_MakeOffsetShape", "Describes functions to build a shell out of a shape. The result is an unlooped shape parallel to the source shape. A MakeOffsetShape object provides a framework for: - defining the construction of a shell - implementing the construction algorithm - consulting the result.");

// Constructors
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<>());
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"));
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"));
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"));
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"));
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"));
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("RemoveIntEdges"));

// Fields

// Methods
// cls_BRepOffsetAPI_MakeOffsetShape.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakeOffsetShape::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeOffsetShape.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakeOffsetShape::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeOffsetShape.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakeOffsetShape::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeOffsetShape.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakeOffsetShape::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeOffsetShape.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakeOffsetShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeOffsetShape.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakeOffsetShape::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformBySimple", (void (BRepOffsetAPI_MakeOffsetShape::*)(const TopoDS_Shape &, const Standard_Real)) &BRepOffsetAPI_MakeOffsetShape::PerformBySimple, "Constructs offset shape for the given one using simple algorithm without intersections computation.", py::arg("theS"), py::arg("theOffsetValue"));
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformByJoin", [](BRepOffsetAPI_MakeOffsetShape &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.PerformByJoin(a0, a1, a2); });
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformByJoin", [](BRepOffsetAPI_MakeOffsetShape &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3) -> void { return self.PerformByJoin(a0, a1, a2, a3); });
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformByJoin", [](BRepOffsetAPI_MakeOffsetShape &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4) -> void { return self.PerformByJoin(a0, a1, a2, a3, a4); });
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformByJoin", [](BRepOffsetAPI_MakeOffsetShape &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4, const Standard_Boolean a5) -> void { return self.PerformByJoin(a0, a1, a2, a3, a4, a5); });
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformByJoin", [](BRepOffsetAPI_MakeOffsetShape &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4, const Standard_Boolean a5, const GeomAbs_JoinType a6) -> void { return self.PerformByJoin(a0, a1, a2, a3, a4, a5, a6); });
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformByJoin", (void (BRepOffsetAPI_MakeOffsetShape::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean)) &BRepOffsetAPI_MakeOffsetShape::PerformByJoin, "Constructs a shape parallel to the shape S, where - S may be a face, a shell, a solid or a compound of these shape kinds; - Offset is the offset value. The offset shape is constructed: - outside S, if Offset is positive, - inside S, if Offset is negative; - Tol defines the coincidence tolerance criterion for generated shapes; - Mode defines the construction type of parallels applied to the free edges of shape S; currently, only one construction type is implemented, namely the one where the free edges do not generate parallels; this corresponds to the default value BRepOffset_Skin; - Intersection specifies how the algorithm must work in order to limit the parallels to two adjacent shapes: - if Intersection is false (default value), the intersection is calculated with the parallels to the two adjacent shapes, - if Intersection is true, the intersection is calculated by taking all generated parallels into account; this computation method is more general as it avoids some self-intersections generated in the offset shape from features of small dimensions on shape S, however this method has not been completely implemented and therefore is not recommended for use; - SelfInter tells the algorithm whether a computation to eliminate self-intersections must be applied to the resulting shape; however, as this functionality is not yet implemented, it is recommended to use the default value (false); - Join defines how to fill the holes that may appear between parallels to the two adjacent faces. It may take values GeomAbs_Arc or GeomAbs_Intersection: - if Join is equal to GeomAbs_Arc, then pipes are generated between two free edges of two adjacent parallels, and spheres are generated on 'images' of vertices; it is the default value, - if Join is equal to GeomAbs_Intersection, then the parallels to the two adjacent faces are enlarged and intersected, so that there are no free edges on parallels to faces. RemoveIntEdges flag defines whether to remove the INTERNAL edges from the result or not. Warnings 1. All the faces of the shape S should be based on the surfaces with continuity at least C1. 2. The offset value should be sufficiently small to avoid self-intersections in resulting shape. Otherwise these self-intersections may appear inside an offset face if its initial surface is not plane or sphere or cylinder, also some non-adjacent offset faces may intersect each other. Also, some offset surfaces may 'turn inside out'. 3. The algorithm may fail if the shape S contains vertices where more than 3 edges converge. 4. Since 3d-offset algorithm involves intersection of surfaces, it is under limitations of surface intersection algorithm. 5. A result cannot be generated if the underlying geometry of S is BSpline with continuity C0. Exceptions Geom_UndefinedDerivative if the underlying geometry of S is BSpline with continuity C0.", py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("RemoveIntEdges"));
cls_BRepOffsetAPI_MakeOffsetShape.def("MakeOffset", (const BRepOffset_MakeOffset & (BRepOffsetAPI_MakeOffsetShape::*)() const) &BRepOffsetAPI_MakeOffsetShape::MakeOffset, "Returns instance of the unrelying intersection / arc algorithm.");
cls_BRepOffsetAPI_MakeOffsetShape.def("Build", (void (BRepOffsetAPI_MakeOffsetShape::*)()) &BRepOffsetAPI_MakeOffsetShape::Build, "Does nothing.");
cls_BRepOffsetAPI_MakeOffsetShape.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_MakeOffsetShape::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakeOffsetShape::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
cls_BRepOffsetAPI_MakeOffsetShape.def("GeneratedEdge", (const TopTools_ListOfShape & (BRepOffsetAPI_MakeOffsetShape::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakeOffsetShape::GeneratedEdge, "Returns the list of edges generated from the shape <S>.", py::arg("S"));
cls_BRepOffsetAPI_MakeOffsetShape.def("GetJoinType", (GeomAbs_JoinType (BRepOffsetAPI_MakeOffsetShape::*)() const) &BRepOffsetAPI_MakeOffsetShape::GetJoinType, "Returns offset join type.");

// Enums

}