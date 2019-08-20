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
#include <BOPDS_DS.hxx>
#include <BOPAlgo_BuilderShape.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <BOPAlgo_PPaveFiller.hxx>
#include <BOPDS_PDS.hxx>
#include <IntTools_Context.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPAlgo_GlueEnum.hxx>
#include <BOPAlgo_PaveFiller.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BOPAlgo_Builder.hxx>

void bind_BOPAlgo_Builder(py::module &mod){

py::class_<BOPAlgo_Builder, std::unique_ptr<BOPAlgo_Builder>, BOPAlgo_BuilderShape> cls_BOPAlgo_Builder(mod, "BOPAlgo_Builder", "The class is a General Fuse algorithm - base algorithm for the algorithms in the Boolean Component. Its main purpose is to build the split parts of the argument shapes from which the result of the operations is combined. The result of the General Fuse algorithm itself is a compound containing all split parts of the arguments.");

// Constructors
cls_BOPAlgo_Builder.def(py::init<>());
cls_BOPAlgo_Builder.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPAlgo_Builder.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_Builder::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_Builder.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_Builder::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_Builder.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_Builder::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_Builder.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_Builder.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_Builder.def("Clear", (void (BOPAlgo_Builder::*)()) &BOPAlgo_Builder::Clear, "Clears the content of the algorithm.");
cls_BOPAlgo_Builder.def("PPaveFiller", (BOPAlgo_PPaveFiller (BOPAlgo_Builder::*)()) &BOPAlgo_Builder::PPaveFiller, "Returns the PaveFiller, algorithm for sub-shapes intersection.");
cls_BOPAlgo_Builder.def("PDS", (BOPDS_PDS (BOPAlgo_Builder::*)()) &BOPAlgo_Builder::PDS, "Returns the Data Structure, holder of intersection information.");
cls_BOPAlgo_Builder.def("Context", (opencascade::handle<IntTools_Context> (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::Context, "Returns the Context, tool for cashing heavy algorithms.");
cls_BOPAlgo_Builder.def("AddArgument", (void (BOPAlgo_Builder::*)(const TopoDS_Shape &)) &BOPAlgo_Builder::AddArgument, "Adds the argument to the operation.", py::arg("theShape"));
cls_BOPAlgo_Builder.def("SetArguments", (void (BOPAlgo_Builder::*)(const TopTools_ListOfShape &)) &BOPAlgo_Builder::SetArguments, "Sets the list of arguments for the operation.", py::arg("theLS"));
cls_BOPAlgo_Builder.def("Arguments", (const TopTools_ListOfShape & (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::Arguments, "Returns the list of arguments.");
cls_BOPAlgo_Builder.def("SetNonDestructive", (void (BOPAlgo_Builder::*)(const Standard_Boolean)) &BOPAlgo_Builder::SetNonDestructive, "Sets the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated. This flag is taken into account if internal PaveFiller is used only. In the case of calling PerformWithFiller the corresponding flag of that PaveFiller is in force.", py::arg("theFlag"));
cls_BOPAlgo_Builder.def("NonDestructive", (Standard_Boolean (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::NonDestructive, "Returns the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.");
cls_BOPAlgo_Builder.def("SetGlue", (void (BOPAlgo_Builder::*)(const BOPAlgo_GlueEnum)) &BOPAlgo_Builder::SetGlue, "Sets the glue option for the algorithm", py::arg("theGlue"));
cls_BOPAlgo_Builder.def("Glue", (BOPAlgo_GlueEnum (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::Glue, "Returns the glue option of the algorithm");
cls_BOPAlgo_Builder.def("SetCheckInverted", (void (BOPAlgo_Builder::*)(const Standard_Boolean)) &BOPAlgo_Builder::SetCheckInverted, "Enables/Disables the check of the input solids for inverted status", py::arg("theCheck"));
cls_BOPAlgo_Builder.def("CheckInverted", (Standard_Boolean (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::CheckInverted, "Returns the flag defining whether the check for input solids on inverted status should be performed or not.");
cls_BOPAlgo_Builder.def("Perform", (void (BOPAlgo_Builder::*)()) &BOPAlgo_Builder::Perform, "Performs the operation. The intersection will be performed also.");
cls_BOPAlgo_Builder.def("PerformWithFiller", (void (BOPAlgo_Builder::*)(const BOPAlgo_PaveFiller &)) &BOPAlgo_Builder::PerformWithFiller, "Performs the operation with the prepared filler. The intersection will not be performed in this case.", py::arg("theFiller"));
cls_BOPAlgo_Builder.def("Generated", (const TopTools_ListOfShape & (BOPAlgo_Builder::*)(const TopoDS_Shape &)) &BOPAlgo_Builder::Generated, "Returns the list of shapes generated from the shape theS.", py::arg("theS"));
cls_BOPAlgo_Builder.def("Modified", (const TopTools_ListOfShape & (BOPAlgo_Builder::*)(const TopoDS_Shape &)) &BOPAlgo_Builder::Modified, "Returns the list of shapes modified from the shape theS.", py::arg("theS"));
cls_BOPAlgo_Builder.def("IsDeleted", (Standard_Boolean (BOPAlgo_Builder::*)(const TopoDS_Shape &)) &BOPAlgo_Builder::IsDeleted, "Returns true if the shape theS has been deleted.", py::arg("theS"));
cls_BOPAlgo_Builder.def("Images", (const TopTools_DataMapOfShapeListOfShape & (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::Images, "Returns the map of images.");
cls_BOPAlgo_Builder.def("Origins", (const TopTools_DataMapOfShapeListOfShape & (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::Origins, "Returns the map of origins.");
cls_BOPAlgo_Builder.def("ShapesSD", (const TopTools_DataMapOfShapeShape & (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::ShapesSD, "Returns the map of Same Domain (SD) shapes - coinciding shapes from different arguments.");

// Enums

}