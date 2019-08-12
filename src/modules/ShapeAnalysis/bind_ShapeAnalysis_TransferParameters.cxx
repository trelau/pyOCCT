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
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <ShapeAnalysis_TransferParameters.hxx>
#include <Standard_Type.hxx>

void bind_ShapeAnalysis_TransferParameters(py::module &mod){

py::class_<ShapeAnalysis_TransferParameters, opencascade::handle<ShapeAnalysis_TransferParameters>, Standard_Transient> cls_ShapeAnalysis_TransferParameters(mod, "ShapeAnalysis_TransferParameters", "This tool is used for transferring parameters from 3d curve of the edge to pcurve and vice versa.");

// Constructors
cls_ShapeAnalysis_TransferParameters.def(py::init<>());
cls_ShapeAnalysis_TransferParameters.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("E"), py::arg("F"));

// Fields

// Methods
cls_ShapeAnalysis_TransferParameters.def("Init", (void (ShapeAnalysis_TransferParameters::*)(const TopoDS_Edge &, const TopoDS_Face &)) &ShapeAnalysis_TransferParameters::Init, "Initialize a tool with edge and face", py::arg("E"), py::arg("F"));
cls_ShapeAnalysis_TransferParameters.def("SetMaxTolerance", (void (ShapeAnalysis_TransferParameters::*)(const Standard_Real)) &ShapeAnalysis_TransferParameters::SetMaxTolerance, "Sets maximal tolerance to use linear recomputation of parameters.", py::arg("maxtol"));
cls_ShapeAnalysis_TransferParameters.def("Perform", (opencascade::handle<TColStd_HSequenceOfReal> (ShapeAnalysis_TransferParameters::*)(const opencascade::handle<TColStd_HSequenceOfReal> &, const Standard_Boolean)) &ShapeAnalysis_TransferParameters::Perform, "Transfers parameters given by sequence Params from 3d curve to pcurve (if To2d is True) or back (if To2d is False)", py::arg("Params"), py::arg("To2d"));
cls_ShapeAnalysis_TransferParameters.def("Perform", (Standard_Real (ShapeAnalysis_TransferParameters::*)(const Standard_Real, const Standard_Boolean)) &ShapeAnalysis_TransferParameters::Perform, "Transfers parameter given by sequence Params from 3d curve to pcurve (if To2d is True) or back (if To2d is False)", py::arg("Param"), py::arg("To2d"));
cls_ShapeAnalysis_TransferParameters.def("TransferRange", (void (ShapeAnalysis_TransferParameters::*)(TopoDS_Edge &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &ShapeAnalysis_TransferParameters::TransferRange, "Recomputes range of curves from NewEdge. If Is2d equals True parameters are recomputed by curve2d else by curve3d.", py::arg("newEdge"), py::arg("prevPar"), py::arg("currPar"), py::arg("To2d"));
cls_ShapeAnalysis_TransferParameters.def("IsSameRange", (Standard_Boolean (ShapeAnalysis_TransferParameters::*)() const) &ShapeAnalysis_TransferParameters::IsSameRange, "Returns True if 3d curve of edge and pcurve are SameRange (in default implementation, if myScale == 1 and myShift == 0)");
cls_ShapeAnalysis_TransferParameters.def_static("get_type_name_", (const char * (*)()) &ShapeAnalysis_TransferParameters::get_type_name, "None");
cls_ShapeAnalysis_TransferParameters.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeAnalysis_TransferParameters::get_type_descriptor, "None");
cls_ShapeAnalysis_TransferParameters.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeAnalysis_TransferParameters::*)() const) &ShapeAnalysis_TransferParameters::DynamicType, "None");

// Enums

}