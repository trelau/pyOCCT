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
#include <Standard_Handle.hxx>
#include <TNaming_NamedShape.hxx>
#include <TDF_LabelMap.hxx>
#include <TDF_Label.hxx>
#include <TNaming_MapOfNamedShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_LabelList.hxx>
#include <TNaming_Localizer.hxx>
#include <TNaming_OldShapeIterator.hxx>
#include <TNaming_UsedShapes.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TNaming_Tool.hxx>

void bind_TNaming_Tool(py::module &mod){

py::class_<TNaming_Tool, std::unique_ptr<TNaming_Tool>> cls_TNaming_Tool(mod, "TNaming_Tool", "A tool to get information on the topology of a named shape attribute. This information is typically a TopoDS_Shape object. Using this tool, relations between named shapes are also accessible.");

// Constructors

// Fields

// Methods
// cls_TNaming_Tool.def_static("operator new_", (void * (*)(size_t)) &TNaming_Tool::operator new, "None", py::arg("theSize"));
// cls_TNaming_Tool.def_static("operator delete_", (void (*)(void *)) &TNaming_Tool::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_Tool.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_Tool::operator new[], "None", py::arg("theSize"));
// cls_TNaming_Tool.def_static("operator delete[]_", (void (*)(void *)) &TNaming_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_Tool.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_Tool.def_static("CurrentShape_", (TopoDS_Shape (*)(const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Tool::CurrentShape, "Returns the last Modification of <NS>. Returns the shape CurrentShape contained in the named shape attribute NS. CurrentShape is the current state of the entities if they have been modified in other attributes of the same data structure. Each call to this function creates a new compound.", py::arg("NS"));
cls_TNaming_Tool.def_static("CurrentShape_", (TopoDS_Shape (*)(const opencascade::handle<TNaming_NamedShape> &, const TDF_LabelMap &)) &TNaming_Tool::CurrentShape, "Returns the shape CurrentShape contained in the named shape attribute NS, and present in the updated attribute map Updated. CurrentShape is the current state of the entities if they have been modified in other attributes of the same data structure. Each call to this function creates a new compound. Warning Only the contents of Updated are searched.R", py::arg("NS"), py::arg("Updated"));
cls_TNaming_Tool.def_static("CurrentNamedShape_", (opencascade::handle<TNaming_NamedShape> (*)(const opencascade::handle<TNaming_NamedShape> &, const TDF_LabelMap &)) &TNaming_Tool::CurrentNamedShape, "Returns the NamedShape of the last Modification of <NS>. This shape is identified by a label.", py::arg("NS"), py::arg("Updated"));
cls_TNaming_Tool.def_static("CurrentNamedShape_", (opencascade::handle<TNaming_NamedShape> (*)(const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Tool::CurrentNamedShape, "Returns NamedShape the last Modification of <NS>.", py::arg("NS"));
cls_TNaming_Tool.def_static("NamedShape_", (opencascade::handle<TNaming_NamedShape> (*)(const TopoDS_Shape &, const TDF_Label &)) &TNaming_Tool::NamedShape, "Returns the named shape attribute defined by the shape aShape and the label anAccess. This attribute is returned as a new shape. You call this function, if you need to create a topological attribute for existing data. Example class MyPkg_MyClass { public: Standard_Boolean SameEdge(const Handle(OCafTest_Line)& , const Handle(CafTest_Line)& ); };", py::arg("aShape"), py::arg("anAcces"));
cls_TNaming_Tool.def_static("GetShape_", (TopoDS_Shape (*)(const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Tool::GetShape, "Returns the entities stored in the named shape attribute NS. If there is only one old-new pair, the new shape is returned. Otherwise, a Compound is returned. This compound is made out of all the new shapes found. Each call to this function creates a new compound.", py::arg("NS"));
cls_TNaming_Tool.def_static("OriginalShape_", (TopoDS_Shape (*)(const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Tool::OriginalShape, "Returns the shape contained as OldShape in <NS>", py::arg("NS"));
cls_TNaming_Tool.def_static("GeneratedShape_", (TopoDS_Shape (*)(const TopoDS_Shape &, const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Tool::GeneratedShape, "Returns the shape generated from S or by a modification of S and contained in the named shape Generation.", py::arg("S"), py::arg("Generation"));
cls_TNaming_Tool.def_static("Collect_", [](const opencascade::handle<TNaming_NamedShape> & a0, TNaming_MapOfNamedShape & a1) -> void { return TNaming_Tool::Collect(a0, a1); });
cls_TNaming_Tool.def_static("Collect_", (void (*)(const opencascade::handle<TNaming_NamedShape> &, TNaming_MapOfNamedShape &, const Standard_Boolean)) &TNaming_Tool::Collect, "None", py::arg("NS"), py::arg("Labels"), py::arg("OnlyModif"));
cls_TNaming_Tool.def_static("HasLabel_", (Standard_Boolean (*)(const TDF_Label &, const TopoDS_Shape &)) &TNaming_Tool::HasLabel, "Returns True if <aShape> appears under a label.(DP)", py::arg("access"), py::arg("aShape"));
cls_TNaming_Tool.def_static("Label_", [](const TDF_Label & access, const TopoDS_Shape & aShape, Standard_Integer & TransDef){ TDF_Label rv = TNaming_Tool::Label(access, aShape, TransDef); return std::tuple<TDF_Label, Standard_Integer &>(rv, TransDef); }, "Returns the label of the first apparition of <aShape>. Transdef is a value of the transaction of the first apparition of <aShape>.", py::arg("access"), py::arg("aShape"), py::arg("TransDef"));
cls_TNaming_Tool.def_static("InitialShape_", (TopoDS_Shape (*)(const TopoDS_Shape &, const TDF_Label &, TDF_LabelList &)) &TNaming_Tool::InitialShape, "Returns the shape created from the shape aShape contained in the attribute anAcces.", py::arg("aShape"), py::arg("anAcces"), py::arg("Labels"));
cls_TNaming_Tool.def_static("ValidUntil_", (Standard_Integer (*)(const TDF_Label &, const TopoDS_Shape &)) &TNaming_Tool::ValidUntil, "Returns the last transaction where the creation of S is valid.", py::arg("access"), py::arg("S"));
cls_TNaming_Tool.def_static("FindShape_", (void (*)(const TDF_LabelMap &, const TDF_LabelMap &, const opencascade::handle<TNaming_NamedShape> &, TopoDS_Shape &)) &TNaming_Tool::FindShape, "Returns the current shape (a Wire or a Shell) built (in the data framework) from the the shapes of the argument named shape. It is used for IDENTITY name type computation.", py::arg("Valid"), py::arg("Forbiden"), py::arg("Arg"), py::arg("S"));

// Enums

}