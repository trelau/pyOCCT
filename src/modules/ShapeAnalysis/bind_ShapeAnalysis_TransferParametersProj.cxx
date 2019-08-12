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
#include <ShapeAnalysis_TransferParameters.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Vertex.hxx>
#include <ShapeAnalysis_TransferParametersProj.hxx>
#include <Standard_Type.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Adaptor3d_CurveOnSurface.hxx>
#include <TopLoc_Location.hxx>

void bind_ShapeAnalysis_TransferParametersProj(py::module &mod){

py::class_<ShapeAnalysis_TransferParametersProj, opencascade::handle<ShapeAnalysis_TransferParametersProj>, ShapeAnalysis_TransferParameters> cls_ShapeAnalysis_TransferParametersProj(mod, "ShapeAnalysis_TransferParametersProj", "This tool is used for transferring parameters from 3d curve of the edge to pcurve and vice versa. This tool transfers parameters with help of projection points from curve 3d on curve 2d and vice versa");

// Constructors
cls_ShapeAnalysis_TransferParametersProj.def(py::init<>());
cls_ShapeAnalysis_TransferParametersProj.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("E"), py::arg("F"));

// Fields

// Methods
cls_ShapeAnalysis_TransferParametersProj.def("Init", (void (ShapeAnalysis_TransferParametersProj::*)(const TopoDS_Edge &, const TopoDS_Face &)) &ShapeAnalysis_TransferParametersProj::Init, "None", py::arg("E"), py::arg("F"));
cls_ShapeAnalysis_TransferParametersProj.def("Perform", (opencascade::handle<TColStd_HSequenceOfReal> (ShapeAnalysis_TransferParametersProj::*)(const opencascade::handle<TColStd_HSequenceOfReal> &, const Standard_Boolean)) &ShapeAnalysis_TransferParametersProj::Perform, "Transfers parameters given by sequence Params from 3d curve to pcurve (if To2d is True) or back (if To2d is False)", py::arg("Papams"), py::arg("To2d"));
cls_ShapeAnalysis_TransferParametersProj.def("Perform", (Standard_Real (ShapeAnalysis_TransferParametersProj::*)(const Standard_Real, const Standard_Boolean)) &ShapeAnalysis_TransferParametersProj::Perform, "Transfers parameter given by Param from 3d curve to pcurve (if To2d is True) or back (if To2d is False)", py::arg("Param"), py::arg("To2d"));
cls_ShapeAnalysis_TransferParametersProj.def("ForceProjection", (Standard_Boolean & (ShapeAnalysis_TransferParametersProj::*)()) &ShapeAnalysis_TransferParametersProj::ForceProjection, "Returns modifiable flag forcing projection If it is False (default), projection is done only if edge is not SameParameter or if tolerance of edge is greater than MaxTolerance()");
cls_ShapeAnalysis_TransferParametersProj.def("TransferRange", (void (ShapeAnalysis_TransferParametersProj::*)(TopoDS_Edge &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &ShapeAnalysis_TransferParametersProj::TransferRange, "Recomputes range of curves from NewEdge. If Is2d equals True parameters are recomputed by curve2d else by curve3d.", py::arg("newEdge"), py::arg("prevPar"), py::arg("currPar"), py::arg("Is2d"));
cls_ShapeAnalysis_TransferParametersProj.def("IsSameRange", (Standard_Boolean (ShapeAnalysis_TransferParametersProj::*)() const) &ShapeAnalysis_TransferParametersProj::IsSameRange, "Returns False;");
cls_ShapeAnalysis_TransferParametersProj.def_static("CopyNMVertex_", (TopoDS_Vertex (*)(const TopoDS_Vertex &, const TopoDS_Edge &, const TopoDS_Edge &)) &ShapeAnalysis_TransferParametersProj::CopyNMVertex, "Make a copy of non-manifold vertex theVert (i.e. create new TVertex and replace PointRepresentations for this vertex from fromedge to toedge. Other representations were copied)", py::arg("theVert"), py::arg("toedge"), py::arg("fromedge"));
cls_ShapeAnalysis_TransferParametersProj.def_static("CopyNMVertex_", (TopoDS_Vertex (*)(const TopoDS_Vertex &, const TopoDS_Face &, const TopoDS_Face &)) &ShapeAnalysis_TransferParametersProj::CopyNMVertex, "Make a copy of non-manifold vertex theVert (i.e. create new TVertex and replace PointRepresentations for this vertex from fromFace to toFace. Other representations were copied)", py::arg("theVert"), py::arg("toFace"), py::arg("fromFace"));
cls_ShapeAnalysis_TransferParametersProj.def_static("get_type_name_", (const char * (*)()) &ShapeAnalysis_TransferParametersProj::get_type_name, "None");
cls_ShapeAnalysis_TransferParametersProj.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeAnalysis_TransferParametersProj::get_type_descriptor, "None");
cls_ShapeAnalysis_TransferParametersProj.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeAnalysis_TransferParametersProj::*)() const) &ShapeAnalysis_TransferParametersProj::DynamicType, "None");

// Enums

}