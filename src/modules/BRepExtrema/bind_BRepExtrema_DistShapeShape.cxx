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
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Extrema_ExtFlag.hxx>
#include <Extrema_ExtAlgo.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <BRepExtrema_SupportType.hxx>
#include <Standard_OStream.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Bnd_SeqOfBox.hxx>
#include <BRepExtrema_SeqOfSolution.hxx>
#include <BRepExtrema_DistShapeShape.hxx>

void bind_BRepExtrema_DistShapeShape(py::module &mod){

py::class_<BRepExtrema_DistShapeShape, std::unique_ptr<BRepExtrema_DistShapeShape, Deleter<BRepExtrema_DistShapeShape>>> cls_BRepExtrema_DistShapeShape(mod, "BRepExtrema_DistShapeShape", "This class provides tools to compute minimum distance between two Shapes (Compound,CompSolid, Solid, Shell, Face, Wire, Edge, Vertex).");

// Constructors
cls_BRepExtrema_DistShapeShape.def(py::init<>());
cls_BRepExtrema_DistShapeShape.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("Shape1"), py::arg("Shape2"));
cls_BRepExtrema_DistShapeShape.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Extrema_ExtFlag>(), py::arg("Shape1"), py::arg("Shape2"), py::arg("F"));
cls_BRepExtrema_DistShapeShape.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("Shape1"), py::arg("Shape2"), py::arg("F"), py::arg("A"));
cls_BRepExtrema_DistShapeShape.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real>(), py::arg("Shape1"), py::arg("Shape2"), py::arg("theDeflection"));
cls_BRepExtrema_DistShapeShape.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real, const Extrema_ExtFlag>(), py::arg("Shape1"), py::arg("Shape2"), py::arg("theDeflection"), py::arg("F"));
cls_BRepExtrema_DistShapeShape.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("Shape1"), py::arg("Shape2"), py::arg("theDeflection"), py::arg("F"), py::arg("A"));

// Fields

// Methods
// cls_BRepExtrema_DistShapeShape.def_static("operator new_", (void * (*)(size_t)) &BRepExtrema_DistShapeShape::operator new, "None", py::arg("theSize"));
// cls_BRepExtrema_DistShapeShape.def_static("operator delete_", (void (*)(void *)) &BRepExtrema_DistShapeShape::operator delete, "None", py::arg("theAddress"));
// cls_BRepExtrema_DistShapeShape.def_static("operator new[]_", (void * (*)(size_t)) &BRepExtrema_DistShapeShape::operator new[], "None", py::arg("theSize"));
// cls_BRepExtrema_DistShapeShape.def_static("operator delete[]_", (void (*)(void *)) &BRepExtrema_DistShapeShape::operator delete[], "None", py::arg("theAddress"));
// cls_BRepExtrema_DistShapeShape.def_static("operator new_", (void * (*)(size_t, void *)) &BRepExtrema_DistShapeShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepExtrema_DistShapeShape.def_static("operator delete_", (void (*)(void *, void *)) &BRepExtrema_DistShapeShape::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepExtrema_DistShapeShape.def("SetDeflection", (void (BRepExtrema_DistShapeShape::*)(const Standard_Real)) &BRepExtrema_DistShapeShape::SetDeflection, "None", py::arg("theDeflection"));
cls_BRepExtrema_DistShapeShape.def("LoadS1", (void (BRepExtrema_DistShapeShape::*)(const TopoDS_Shape &)) &BRepExtrema_DistShapeShape::LoadS1, "load first shape into extrema", py::arg("Shape1"));
cls_BRepExtrema_DistShapeShape.def("LoadS2", (void (BRepExtrema_DistShapeShape::*)(const TopoDS_Shape &)) &BRepExtrema_DistShapeShape::LoadS2, "load second shape into extrema", py::arg("Shape1"));
cls_BRepExtrema_DistShapeShape.def("Perform", (Standard_Boolean (BRepExtrema_DistShapeShape::*)()) &BRepExtrema_DistShapeShape::Perform, "computation of the minimum distance (value and couple of points). Parameter theDeflection is used to specify a maximum deviation of extreme distances from the minimum one. Returns IsDone status.");
cls_BRepExtrema_DistShapeShape.def("IsDone", (Standard_Boolean (BRepExtrema_DistShapeShape::*)() const) &BRepExtrema_DistShapeShape::IsDone, "True if the minimum distance is found.");
cls_BRepExtrema_DistShapeShape.def("NbSolution", (Standard_Integer (BRepExtrema_DistShapeShape::*)() const) &BRepExtrema_DistShapeShape::NbSolution, "Returns the number of solutions satisfying the minimum distance.");
cls_BRepExtrema_DistShapeShape.def("Value", (Standard_Real (BRepExtrema_DistShapeShape::*)() const) &BRepExtrema_DistShapeShape::Value, "Returns the value of the minimum distance.");
cls_BRepExtrema_DistShapeShape.def("InnerSolution", (Standard_Boolean (BRepExtrema_DistShapeShape::*)() const) &BRepExtrema_DistShapeShape::InnerSolution, "True if one of the shapes is a solid and the other shape is completely or partially inside the solid.");
cls_BRepExtrema_DistShapeShape.def("PointOnShape1", (const gp_Pnt & (BRepExtrema_DistShapeShape::*)(const Standard_Integer) const) &BRepExtrema_DistShapeShape::PointOnShape1, "Returns the Point corresponding to the <N>th solution on the first Shape", py::arg("N"));
cls_BRepExtrema_DistShapeShape.def("PointOnShape2", (const gp_Pnt & (BRepExtrema_DistShapeShape::*)(const Standard_Integer) const) &BRepExtrema_DistShapeShape::PointOnShape2, "Returns the Point corresponding to the <N>th solution on the second Shape", py::arg("N"));
cls_BRepExtrema_DistShapeShape.def("SupportTypeShape1", (BRepExtrema_SupportType (BRepExtrema_DistShapeShape::*)(const Standard_Integer) const) &BRepExtrema_DistShapeShape::SupportTypeShape1, "gives the type of the support where the Nth solution on the first shape is situated: IsVertex => the Nth solution on the first shape is a Vertex IsOnEdge => the Nth soluion on the first shape is on a Edge IsInFace => the Nth solution on the first shape is inside a face the corresponding support is obtained by the method SupportOnShape1", py::arg("N"));
cls_BRepExtrema_DistShapeShape.def("SupportTypeShape2", (BRepExtrema_SupportType (BRepExtrema_DistShapeShape::*)(const Standard_Integer) const) &BRepExtrema_DistShapeShape::SupportTypeShape2, "gives the type of the support where the Nth solution on the second shape is situated: IsVertex => the Nth solution on the second shape is a Vertex IsOnEdge => the Nth soluion on the secondt shape is on a Edge IsInFace => the Nth solution on the second shape is inside a face the corresponding support is obtained by the method SupportOnShape2", py::arg("N"));
cls_BRepExtrema_DistShapeShape.def("SupportOnShape1", (TopoDS_Shape (BRepExtrema_DistShapeShape::*)(const Standard_Integer) const) &BRepExtrema_DistShapeShape::SupportOnShape1, "gives the support where the Nth solution on the first shape is situated. This support can be a Vertex, an Edge or a Face.", py::arg("N"));
cls_BRepExtrema_DistShapeShape.def("SupportOnShape2", (TopoDS_Shape (BRepExtrema_DistShapeShape::*)(const Standard_Integer) const) &BRepExtrema_DistShapeShape::SupportOnShape2, "gives the support where the Nth solution on the second shape is situated. This support can be a Vertex, an Edge or a Face.", py::arg("N"));
cls_BRepExtrema_DistShapeShape.def("ParOnEdgeS1", [](BRepExtrema_DistShapeShape &self, const Standard_Integer N, Standard_Real & t){ self.ParOnEdgeS1(N, t); return t; }, "gives the corresponding parameter t if the Nth solution is situated on an Egde of the first shape", py::arg("N"), py::arg("t"));
cls_BRepExtrema_DistShapeShape.def("ParOnEdgeS2", [](BRepExtrema_DistShapeShape &self, const Standard_Integer N, Standard_Real & t){ self.ParOnEdgeS2(N, t); return t; }, "gives the corresponding parameter t if the Nth solution is situated on an Egde of the first shape", py::arg("N"), py::arg("t"));
cls_BRepExtrema_DistShapeShape.def("ParOnFaceS1", [](BRepExtrema_DistShapeShape &self, const Standard_Integer N, Standard_Real & u, Standard_Real & v){ self.ParOnFaceS1(N, u, v); return std::tuple<Standard_Real &, Standard_Real &>(u, v); }, "gives the corresponding parameters (U,V) if the Nth solution is situated on an face of the first shape", py::arg("N"), py::arg("u"), py::arg("v"));
cls_BRepExtrema_DistShapeShape.def("ParOnFaceS2", [](BRepExtrema_DistShapeShape &self, const Standard_Integer N, Standard_Real & u, Standard_Real & v){ self.ParOnFaceS2(N, u, v); return std::tuple<Standard_Real &, Standard_Real &>(u, v); }, "gives the corresponding parameters (U,V) if the Nth solution is situated on an Face of the second shape", py::arg("N"), py::arg("u"), py::arg("v"));
cls_BRepExtrema_DistShapeShape.def("Dump", (void (BRepExtrema_DistShapeShape::*)(Standard_OStream &) const) &BRepExtrema_DistShapeShape::Dump, "Prints on the stream o information on the current state of the object.", py::arg("o"));
cls_BRepExtrema_DistShapeShape.def("SetFlag", (void (BRepExtrema_DistShapeShape::*)(const Extrema_ExtFlag)) &BRepExtrema_DistShapeShape::SetFlag, "None", py::arg("F"));
cls_BRepExtrema_DistShapeShape.def("SetAlgo", (void (BRepExtrema_DistShapeShape::*)(const Extrema_ExtAlgo)) &BRepExtrema_DistShapeShape::SetAlgo, "None", py::arg("A"));

// Enums

}