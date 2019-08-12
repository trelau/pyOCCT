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
#include <Standard_Transient.hxx>
#include <GeomFill_PipeError.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Standard_Handle.hxx>
#include <GeomFill_LocationLaw.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepFill_LocationLaw.hxx>
#include <Standard_Type.hxx>
#include <GeomFill_HArray1OfLocationLaw.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TopTools_HArray1OfShape.hxx>
#include <TColStd_HArray1OfInteger.hxx>

void bind_BRepFill_LocationLaw(py::module &mod){

py::class_<BRepFill_LocationLaw, opencascade::handle<BRepFill_LocationLaw>, Standard_Transient> cls_BRepFill_LocationLaw(mod, "BRepFill_LocationLaw", "Location Law on a Wire.");

// Constructors

// Fields

// Methods
cls_BRepFill_LocationLaw.def("GetStatus", (GeomFill_PipeError (BRepFill_LocationLaw::*)() const) &BRepFill_LocationLaw::GetStatus, "Return a error status, if the status is not PipeOk then it exist a parameter tlike the law is not valuable for t.");
cls_BRepFill_LocationLaw.def("TransformInG0Law", (void (BRepFill_LocationLaw::*)()) &BRepFill_LocationLaw::TransformInG0Law, "Apply a linear transformation on each law, to have continuity of the global law beetween the edges.");
cls_BRepFill_LocationLaw.def("TransformInCompatibleLaw", (void (BRepFill_LocationLaw::*)(const Standard_Real)) &BRepFill_LocationLaw::TransformInCompatibleLaw, "Apply a linear transformation on each law, to reduce the dicontinuities of law at one rotation.", py::arg("AngularTolerance"));
cls_BRepFill_LocationLaw.def("DeleteTransform", (void (BRepFill_LocationLaw::*)()) &BRepFill_LocationLaw::DeleteTransform, "None");
cls_BRepFill_LocationLaw.def("NbHoles", [](BRepFill_LocationLaw &self) -> Standard_Integer { return self.NbHoles(); });
cls_BRepFill_LocationLaw.def("NbHoles", (Standard_Integer (BRepFill_LocationLaw::*)(const Standard_Real)) &BRepFill_LocationLaw::NbHoles, "None", py::arg("Tol"));
cls_BRepFill_LocationLaw.def("Holes", (void (BRepFill_LocationLaw::*)(TColStd_Array1OfInteger &) const) &BRepFill_LocationLaw::Holes, "None", py::arg("Interval"));
cls_BRepFill_LocationLaw.def("NbLaw", (Standard_Integer (BRepFill_LocationLaw::*)() const) &BRepFill_LocationLaw::NbLaw, "Return the number of elementary Law");
cls_BRepFill_LocationLaw.def("Law", (const opencascade::handle<GeomFill_LocationLaw> & (BRepFill_LocationLaw::*)(const Standard_Integer) const) &BRepFill_LocationLaw::Law, "Return the elementary Law of rank <Index> <Index> have to be in [1, NbLaw()]", py::arg("Index"));
cls_BRepFill_LocationLaw.def("Wire", (const TopoDS_Wire & (BRepFill_LocationLaw::*)() const) &BRepFill_LocationLaw::Wire, "return the path");
cls_BRepFill_LocationLaw.def("Edge", (const TopoDS_Edge & (BRepFill_LocationLaw::*)(const Standard_Integer) const) &BRepFill_LocationLaw::Edge, "Return the Edge of rank <Index> in the path <Index> have to be in [1, NbLaw()]", py::arg("Index"));
cls_BRepFill_LocationLaw.def("Vertex", (TopoDS_Vertex (BRepFill_LocationLaw::*)(const Standard_Integer) const) &BRepFill_LocationLaw::Vertex, "Return the vertex of rank <Index> in the path <Index> have to be in [0, NbLaw()]", py::arg("Index"));
cls_BRepFill_LocationLaw.def("PerformVertex", [](BRepFill_LocationLaw &self, const Standard_Integer a0, const TopoDS_Vertex & a1, const Standard_Real a2, TopoDS_Vertex & a3) -> void { return self.PerformVertex(a0, a1, a2, a3); });
cls_BRepFill_LocationLaw.def("PerformVertex", (void (BRepFill_LocationLaw::*)(const Standard_Integer, const TopoDS_Vertex &, const Standard_Real, TopoDS_Vertex &, const Standard_Integer) const) &BRepFill_LocationLaw::PerformVertex, "Compute <OutputVertex> like a transformation of <InputVertex> the transformation is given by evaluation of the location law in the vertex of rank <Index>. <Location> is used to manage discontinuities : - -1 : The law before the vertex is used. - 1 : The law after the vertex is used. - 0 : Average of the both laws is used.", py::arg("Index"), py::arg("InputVertex"), py::arg("TolMin"), py::arg("OutputVertex"), py::arg("Location"));
cls_BRepFill_LocationLaw.def("CurvilinearBounds", [](BRepFill_LocationLaw &self, const Standard_Integer Index, Standard_Real & First, Standard_Real & Last){ self.CurvilinearBounds(Index, First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Return the Curvilinear Bounds of the <Index> Law", py::arg("Index"), py::arg("First"), py::arg("Last"));
cls_BRepFill_LocationLaw.def("IsClosed", (Standard_Boolean (BRepFill_LocationLaw::*)() const) &BRepFill_LocationLaw::IsClosed, "None");
cls_BRepFill_LocationLaw.def("IsG1", [](BRepFill_LocationLaw &self, const Standard_Integer a0) -> Standard_Integer { return self.IsG1(a0); });
cls_BRepFill_LocationLaw.def("IsG1", [](BRepFill_LocationLaw &self, const Standard_Integer a0, const Standard_Real a1) -> Standard_Integer { return self.IsG1(a0, a1); });
cls_BRepFill_LocationLaw.def("IsG1", (Standard_Integer (BRepFill_LocationLaw::*)(const Standard_Integer, const Standard_Real, const Standard_Real) const) &BRepFill_LocationLaw::IsG1, "Compute the Law's continuity beetween 2 edges of the path The result can be : -1 : Case Not connex 0 : It is connex (G0) 1 : It is tangent (G1)", py::arg("Index"), py::arg("SpatialTolerance"), py::arg("AngularTolerance"));
cls_BRepFill_LocationLaw.def("D0", (void (BRepFill_LocationLaw::*)(const Standard_Real, TopoDS_Shape &)) &BRepFill_LocationLaw::D0, "Apply the Law to a shape, for a given Curnilinear abscissa", py::arg("Abscissa"), py::arg("Section"));
cls_BRepFill_LocationLaw.def("Parameter", [](BRepFill_LocationLaw &self, const Standard_Real Abscissa, Standard_Integer & Index, Standard_Real & Param){ self.Parameter(Abscissa, Index, Param); return std::tuple<Standard_Integer &, Standard_Real &>(Index, Param); }, "Find the index Law and the parmaeter, for a given Curnilinear abscissa", py::arg("Abscissa"), py::arg("Index"), py::arg("Param"));
cls_BRepFill_LocationLaw.def("Abscissa", (Standard_Real (BRepFill_LocationLaw::*)(const Standard_Integer, const Standard_Real)) &BRepFill_LocationLaw::Abscissa, "Return the curvilinear abscissa corresponding to a point of the path, defined by <Index> of Edge and a parameter on the edge.", py::arg("Index"), py::arg("Param"));
cls_BRepFill_LocationLaw.def_static("get_type_name_", (const char * (*)()) &BRepFill_LocationLaw::get_type_name, "None");
cls_BRepFill_LocationLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_LocationLaw::get_type_descriptor, "None");
cls_BRepFill_LocationLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_LocationLaw::*)() const) &BRepFill_LocationLaw::DynamicType, "None");

// Enums

}