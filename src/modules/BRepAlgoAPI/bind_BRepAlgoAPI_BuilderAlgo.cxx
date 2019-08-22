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
#include <BOPAlgo_Builder.hxx>
#include <BRepAlgoAPI_Algo.hxx>
#include <Standard.hxx>
#include <BOPAlgo_PaveFiller.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPAlgo_GlueEnum.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <BOPAlgo_PPaveFiller.hxx>
#include <BOPAlgo_PBuilder.hxx>
#include <BRepAlgoAPI_BuilderAlgo.hxx>

void bind_BRepAlgoAPI_BuilderAlgo(py::module &mod){

py::class_<BRepAlgoAPI_BuilderAlgo, BRepAlgoAPI_Algo> cls_BRepAlgoAPI_BuilderAlgo(mod, "BRepAlgoAPI_BuilderAlgo", "The class contains API level of the General Fuse algorithm.");

// Constructors
cls_BRepAlgoAPI_BuilderAlgo.def(py::init<>());
cls_BRepAlgoAPI_BuilderAlgo.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("thePF"));

// Fields

// Methods
// cls_BRepAlgoAPI_BuilderAlgo.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_BuilderAlgo::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_BuilderAlgo.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_BuilderAlgo::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_BuilderAlgo.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_BuilderAlgo::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_BuilderAlgo.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_BuilderAlgo::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_BuilderAlgo.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_BuilderAlgo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_BuilderAlgo.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_BuilderAlgo::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgoAPI_BuilderAlgo.def("SetNonDestructive", (void (BRepAlgoAPI_BuilderAlgo::*)(const Standard_Boolean)) &BRepAlgoAPI_BuilderAlgo::SetNonDestructive, "Sets the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.", py::arg("theFlag"));
cls_BRepAlgoAPI_BuilderAlgo.def("NonDestructive", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::NonDestructive, "Returns the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.");
cls_BRepAlgoAPI_BuilderAlgo.def("SetGlue", (void (BRepAlgoAPI_BuilderAlgo::*)(const BOPAlgo_GlueEnum)) &BRepAlgoAPI_BuilderAlgo::SetGlue, "Sets the glue option for the algorithm", py::arg("theGlue"));
cls_BRepAlgoAPI_BuilderAlgo.def("Glue", (BOPAlgo_GlueEnum (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::Glue, "Returns the glue option of the algorithm");
cls_BRepAlgoAPI_BuilderAlgo.def("SetCheckInverted", (void (BRepAlgoAPI_BuilderAlgo::*)(const Standard_Boolean)) &BRepAlgoAPI_BuilderAlgo::SetCheckInverted, "Enables/Disables the check of the input solids for inverted status", py::arg("theCheck"));
cls_BRepAlgoAPI_BuilderAlgo.def("CheckInverted", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::CheckInverted, "Returns the flag defining whether the check for input solids on inverted status should be performed or not.");
cls_BRepAlgoAPI_BuilderAlgo.def("SetArguments", (void (BRepAlgoAPI_BuilderAlgo::*)(const TopTools_ListOfShape &)) &BRepAlgoAPI_BuilderAlgo::SetArguments, "Sets the arguments", py::arg("theLS"));
cls_BRepAlgoAPI_BuilderAlgo.def("Arguments", (const TopTools_ListOfShape & (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::Arguments, "Gets the arguments");
cls_BRepAlgoAPI_BuilderAlgo.def("Build", (void (BRepAlgoAPI_BuilderAlgo::*)()) &BRepAlgoAPI_BuilderAlgo::Build, "Performs the algorithm");
cls_BRepAlgoAPI_BuilderAlgo.def("Modified", (const TopTools_ListOfShape & (BRepAlgoAPI_BuilderAlgo::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BuilderAlgo::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("aS"));
cls_BRepAlgoAPI_BuilderAlgo.def("IsDeleted", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BuilderAlgo::IsDeleted, "Returns true if the shape S has been deleted. The result shape of the operation does not contain the shape S.", py::arg("aS"));
cls_BRepAlgoAPI_BuilderAlgo.def("Generated", (const TopTools_ListOfShape & (BRepAlgoAPI_BuilderAlgo::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BuilderAlgo::Generated, "Returns the list of shapes generated from the shape <S>. For use in BRepNaming.", py::arg("S"));
cls_BRepAlgoAPI_BuilderAlgo.def("HasModified", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::HasModified, "Returns true if there is at least one modified shape. For use in BRepNaming.");
cls_BRepAlgoAPI_BuilderAlgo.def("HasGenerated", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::HasGenerated, "Returns true if there is at least one generated shape. For use in BRepNaming.");
cls_BRepAlgoAPI_BuilderAlgo.def("HasDeleted", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::HasDeleted, "Returns true if there is at least one deleted shape. For use in BRepNaming.");
cls_BRepAlgoAPI_BuilderAlgo.def("DSFiller", (const BOPAlgo_PPaveFiller & (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::DSFiller, "Returns the Intersection tool");
cls_BRepAlgoAPI_BuilderAlgo.def("Builder", (const BOPAlgo_PBuilder & (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::Builder, "Returns the Building tool");

// Enums

}