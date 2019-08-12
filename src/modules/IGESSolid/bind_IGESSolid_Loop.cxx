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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESBasic_HArray1OfHArray1OfInteger.hxx>
#include <IGESBasic_HArray1OfHArray1OfIGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESSolid_Loop.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_Loop(py::module &mod){

py::class_<IGESSolid_Loop, opencascade::handle<IGESSolid_Loop>, IGESData_IGESEntity> cls_IGESSolid_Loop(mod, "IGESSolid_Loop", "defines Loop, Type <508> Form Number <1> in package IGESSolid A Loop entity specifies a bound of a face. It represents a connected collection of face boundaries, seams, and poles of a single face.");

// Constructors
cls_IGESSolid_Loop.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_Loop.def("Init", (void (IGESSolid_Loop::*)(const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfIGESEntity> &)) &IGESSolid_Loop::Init, "This method is used to set the fields of the class Loop - types : 0 = Edge; 1 = Vertex - edges : Pointer to the EdgeList or VertexList - index : Index of the edge into the EdgeList VertexList entity - orient : Orientation flag of the edge - nbParameterCurves : the number of parameter space curves for each edge - isoparametricFlags : the isoparametric flag of the parameter space curve - curves : the parameter space curves raises exception if length of types, edges, index, orient and nbParameterCurves do not match or the length of isoparametricFlags and curves do not match", py::arg("types"), py::arg("edges"), py::arg("index"), py::arg("orient"), py::arg("nbParameterCurves"), py::arg("isoparametricFlags"), py::arg("curves"));
cls_IGESSolid_Loop.def("IsBound", (Standard_Boolean (IGESSolid_Loop::*)() const) &IGESSolid_Loop::IsBound, "Tells if a Loop is a Bound (FN 1) else it is free (FN 0)");
cls_IGESSolid_Loop.def("SetBound", (void (IGESSolid_Loop::*)(const Standard_Boolean)) &IGESSolid_Loop::SetBound, "Sets or Unset the Bound Status (from Form Number) Default is True", py::arg("bound"));
cls_IGESSolid_Loop.def("NbEdges", (Standard_Integer (IGESSolid_Loop::*)() const) &IGESSolid_Loop::NbEdges, "returns the number of edge tuples");
cls_IGESSolid_Loop.def("EdgeType", (Standard_Integer (IGESSolid_Loop::*)(const Standard_Integer) const) &IGESSolid_Loop::EdgeType, "returns the type of Index'th edge (0 = Edge, 1 = Vertex) raises exception if Index <= 0 or Index > NbEdges()", py::arg("Index"));
cls_IGESSolid_Loop.def("Edge", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_Loop::*)(const Standard_Integer) const) &IGESSolid_Loop::Edge, "return the EdgeList or VertexList corresponding to the Index raises exception if Index <= 0 or Index > NbEdges()", py::arg("Index"));
cls_IGESSolid_Loop.def("Orientation", (Standard_Boolean (IGESSolid_Loop::*)(const Standard_Integer) const) &IGESSolid_Loop::Orientation, "returns the orientation flag corresponding to Index'th edge raises exception if Index <= 0 or Index > NbEdges()", py::arg("Index"));
cls_IGESSolid_Loop.def("NbParameterCurves", (Standard_Integer (IGESSolid_Loop::*)(const Standard_Integer) const) &IGESSolid_Loop::NbParameterCurves, "return the number of parameter space curves associated with Index'th Edge raises exception if Index <= 0 or Index > NbEdges()", py::arg("Index"));
cls_IGESSolid_Loop.def("IsIsoparametric", (Standard_Boolean (IGESSolid_Loop::*)(const Standard_Integer, const Standard_Integer) const) &IGESSolid_Loop::IsIsoparametric, "None", py::arg("EdgeIndex"), py::arg("CurveIndex"));
cls_IGESSolid_Loop.def("ParametricCurve", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_Loop::*)(const Standard_Integer, const Standard_Integer) const) &IGESSolid_Loop::ParametricCurve, "returns the CurveIndex'th parameter space curve associated with EdgeIndex'th edge raises exception if EdgeIndex <= 0 or EdgeIndex > NbEdges() or if CurveIndex <= 0 or CurveIndex > NbParameterCurves(EdgeIndex)", py::arg("EdgeIndex"), py::arg("CurveIndex"));
cls_IGESSolid_Loop.def("ListIndex", (Standard_Integer (IGESSolid_Loop::*)(const Standard_Integer) const) &IGESSolid_Loop::ListIndex, "raises exception If num <= 0 or num > NbEdges()", py::arg("num"));
cls_IGESSolid_Loop.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Loop::get_type_name, "None");
cls_IGESSolid_Loop.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Loop::get_type_descriptor, "None");
cls_IGESSolid_Loop.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Loop::*)() const) &IGESSolid_Loop::DynamicType, "None");

// Enums

}