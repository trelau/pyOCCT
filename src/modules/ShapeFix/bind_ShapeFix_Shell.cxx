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
#include <ShapeFix_Root.hxx>
#include <TopoDS_Shell.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Message_ProgressIndicator.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Compound.hxx>
#include <ShapeExtend_Status.hxx>
#include <ShapeFix_Face.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <ShapeFix_Shell.hxx>
#include <Standard_Type.hxx>

void bind_ShapeFix_Shell(py::module &mod){

py::class_<ShapeFix_Shell, opencascade::handle<ShapeFix_Shell>, ShapeFix_Root> cls_ShapeFix_Shell(mod, "ShapeFix_Shell", "Fixing orientation of faces in shell");

// Constructors
cls_ShapeFix_Shell.def(py::init<>());
cls_ShapeFix_Shell.def(py::init<const TopoDS_Shell &>(), py::arg("shape"));

// Fields

// Methods
cls_ShapeFix_Shell.def("Init", (void (ShapeFix_Shell::*)(const TopoDS_Shell &)) &ShapeFix_Shell::Init, "Initializes by shell.", py::arg("shell"));
cls_ShapeFix_Shell.def("Perform", [](ShapeFix_Shell &self) -> Standard_Boolean { return self.Perform(); });
cls_ShapeFix_Shell.def("Perform", (Standard_Boolean (ShapeFix_Shell::*)(const opencascade::handle<Message_ProgressIndicator> &)) &ShapeFix_Shell::Perform, "Iterates on subshapes and performs fixes (for each face calls ShapeFix_Face::Perform and then calls FixFaceOrientation). The passed progress indicator allows user to consult the current progress stage and abort algorithm if needed.", py::arg("theProgress"));
cls_ShapeFix_Shell.def("FixFaceOrientation", [](ShapeFix_Shell &self, const TopoDS_Shell & a0) -> Standard_Boolean { return self.FixFaceOrientation(a0); });
cls_ShapeFix_Shell.def("FixFaceOrientation", [](ShapeFix_Shell &self, const TopoDS_Shell & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.FixFaceOrientation(a0, a1); });
cls_ShapeFix_Shell.def("FixFaceOrientation", (Standard_Boolean (ShapeFix_Shell::*)(const TopoDS_Shell &, const Standard_Boolean, const Standard_Boolean)) &ShapeFix_Shell::FixFaceOrientation, "Fixes orientation of faces in shell. Changes orientation of face in the shell, if it is oriented opposite to neigbouring faces. If it is not possible to orient all faces in the shell (like in case of mebious band), this method orients only subset of faces. Other faces are stored in Error compound. Modes : isAccountMultiConex - mode for account cases of multiconnexity. If this mode is equal to Standard_True, separate shells will be created in the cases of multiconnexity. If this mode is equal to Standard_False, one shell will be created without account of multiconnexity.By defautt - Standard_True; NonManifold - mode for creation of non-manifold shells. If this mode is equal to Standard_True one non-manifold will be created from shell contains multishared edges. Else if this mode is equal to Standard_False only manifold shells will be created. By default - Standard_False.", py::arg("shell"), py::arg("isAccountMultiConex"), py::arg("NonManifold"));
cls_ShapeFix_Shell.def("Shell", (TopoDS_Shell (ShapeFix_Shell::*)()) &ShapeFix_Shell::Shell, "Returns fixed shell (or subset of oriented faces).");
cls_ShapeFix_Shell.def("Shape", (TopoDS_Shape (ShapeFix_Shell::*)()) &ShapeFix_Shell::Shape, "In case of multiconnexity returns compound of fixed shells else returns one shell..");
cls_ShapeFix_Shell.def("NbShells", (Standard_Integer (ShapeFix_Shell::*)() const) &ShapeFix_Shell::NbShells, "Returns Number of obtainrd shells;");
cls_ShapeFix_Shell.def("ErrorFaces", (TopoDS_Compound (ShapeFix_Shell::*)() const) &ShapeFix_Shell::ErrorFaces, "Returns not oriented subset of faces.");
cls_ShapeFix_Shell.def("Status", (Standard_Boolean (ShapeFix_Shell::*)(const ShapeExtend_Status) const) &ShapeFix_Shell::Status, "Returns the status of the last Fix.", py::arg("status"));
cls_ShapeFix_Shell.def("FixFaceTool", (opencascade::handle<ShapeFix_Face> (ShapeFix_Shell::*)()) &ShapeFix_Shell::FixFaceTool, "Returns tool for fixing faces.");
cls_ShapeFix_Shell.def("SetMsgRegistrator", (void (ShapeFix_Shell::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeFix_Shell::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
cls_ShapeFix_Shell.def("SetPrecision", (void (ShapeFix_Shell::*)(const Standard_Real)) &ShapeFix_Shell::SetPrecision, "Sets basic precision value (also to FixWireTool)", py::arg("preci"));
cls_ShapeFix_Shell.def("SetMinTolerance", (void (ShapeFix_Shell::*)(const Standard_Real)) &ShapeFix_Shell::SetMinTolerance, "Sets minimal allowed tolerance (also to FixWireTool)", py::arg("mintol"));
cls_ShapeFix_Shell.def("SetMaxTolerance", (void (ShapeFix_Shell::*)(const Standard_Real)) &ShapeFix_Shell::SetMaxTolerance, "Sets maximal allowed tolerance (also to FixWireTool)", py::arg("maxtol"));
cls_ShapeFix_Shell.def("FixFaceMode", (Standard_Integer & (ShapeFix_Shell::*)()) &ShapeFix_Shell::FixFaceMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Face, by default True.");
cls_ShapeFix_Shell.def("FixOrientationMode", (Standard_Integer & (ShapeFix_Shell::*)()) &ShapeFix_Shell::FixOrientationMode, "Returns (modifiable) the mode for applying FixFaceOrientation, by default True.");
cls_ShapeFix_Shell.def("SetNonManifoldFlag", (void (ShapeFix_Shell::*)(const Standard_Boolean)) &ShapeFix_Shell::SetNonManifoldFlag, "Sets NonManifold flag", py::arg("isNonManifold"));
cls_ShapeFix_Shell.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Shell::get_type_name, "None");
cls_ShapeFix_Shell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Shell::get_type_descriptor, "None");
cls_ShapeFix_Shell.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Shell::*)() const) &ShapeFix_Shell::DynamicType, "None");

// Enums

}