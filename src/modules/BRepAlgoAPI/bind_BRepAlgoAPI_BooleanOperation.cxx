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
#include <BRepAlgoAPI_BuilderAlgo.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BOPAlgo_Operation.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPAlgo_PaveFiller.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepAlgoAPI_BooleanOperation.hxx>

void bind_BRepAlgoAPI_BooleanOperation(py::module &mod){

py::class_<BRepAlgoAPI_BooleanOperation, std::unique_ptr<BRepAlgoAPI_BooleanOperation>, BRepAlgoAPI_BuilderAlgo> cls_BRepAlgoAPI_BooleanOperation(mod, "BRepAlgoAPI_BooleanOperation", "The abstract class BooleanOperation is the root class of Boolean Operations (see Overview). Boolean Operations algorithm is divided onto two parts: - The first one is computing interference between arguments; - The second one is building the result of operation; The class BooleanOperation provides API level of both parts.");

// Constructors

// Fields

// Methods
// cls_BRepAlgoAPI_BooleanOperation.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_BooleanOperation::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_BooleanOperation.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_BooleanOperation::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_BooleanOperation.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_BooleanOperation::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_BooleanOperation.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_BooleanOperation::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_BooleanOperation.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_BooleanOperation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_BooleanOperation.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_BooleanOperation::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgoAPI_BooleanOperation.def("Shape1", (const TopoDS_Shape & (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::Shape1, "Returns the first argument involved in this Boolean operation. Obsolete");
cls_BRepAlgoAPI_BooleanOperation.def("Shape2", (const TopoDS_Shape & (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::Shape2, "Returns the second argument involved in this Boolean operation. Obsolete");
cls_BRepAlgoAPI_BooleanOperation.def("SetTools", (void (BRepAlgoAPI_BooleanOperation::*)(const TopTools_ListOfShape &)) &BRepAlgoAPI_BooleanOperation::SetTools, "Sets the tools", py::arg("theLS"));
cls_BRepAlgoAPI_BooleanOperation.def("Tools", (const TopTools_ListOfShape & (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::Tools, "Gets the tools");
cls_BRepAlgoAPI_BooleanOperation.def("SetOperation", (void (BRepAlgoAPI_BooleanOperation::*)(const BOPAlgo_Operation)) &BRepAlgoAPI_BooleanOperation::SetOperation, "Sets the type of Boolean operation", py::arg("anOp"));
cls_BRepAlgoAPI_BooleanOperation.def("Operation", (BOPAlgo_Operation (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::Operation, "Returns the type of Boolean Operation");
cls_BRepAlgoAPI_BooleanOperation.def("Build", (void (BRepAlgoAPI_BooleanOperation::*)()) &BRepAlgoAPI_BooleanOperation::Build, "Performs the algorithm Filling interference Data Structure (if it is necessary) Building the result of the operation.");
cls_BRepAlgoAPI_BooleanOperation.def("BuilderCanWork", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::BuilderCanWork, "Returns True if there was no errors occured obsolete");
cls_BRepAlgoAPI_BooleanOperation.def("FuseEdges", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::FuseEdges, "Returns the flag of edge refining");
cls_BRepAlgoAPI_BooleanOperation.def("RefineEdges", (void (BRepAlgoAPI_BooleanOperation::*)()) &BRepAlgoAPI_BooleanOperation::RefineEdges, "Fuse C1 edges");
cls_BRepAlgoAPI_BooleanOperation.def("SectionEdges", (const TopTools_ListOfShape & (BRepAlgoAPI_BooleanOperation::*)()) &BRepAlgoAPI_BooleanOperation::SectionEdges, "Returns a list of section edges. The edges represent the result of intersection between arguments of Boolean Operation. They are computed during operation execution.");
cls_BRepAlgoAPI_BooleanOperation.def("Modified", (const TopTools_ListOfShape & (BRepAlgoAPI_BooleanOperation::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BooleanOperation::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("aS"));
cls_BRepAlgoAPI_BooleanOperation.def("IsDeleted", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BooleanOperation::IsDeleted, "Returns true if the shape S has been deleted. The result shape of the operation does not contain the shape S.", py::arg("aS"));
cls_BRepAlgoAPI_BooleanOperation.def("Generated", (const TopTools_ListOfShape & (BRepAlgoAPI_BooleanOperation::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BooleanOperation::Generated, "Returns the list of shapes generated from the shape <S>. For use in BRepNaming.", py::arg("S"));
cls_BRepAlgoAPI_BooleanOperation.def("HasModified", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::HasModified, "Returns true if there is at least one modified shape. For use in BRepNaming.");
cls_BRepAlgoAPI_BooleanOperation.def("HasGenerated", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::HasGenerated, "Returns true if there is at least one generated shape. For use in BRepNaming.");
cls_BRepAlgoAPI_BooleanOperation.def("HasDeleted", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::HasDeleted, "Returns true if there is at least one deleted shape. For use in BRepNaming.");

// Enums

}