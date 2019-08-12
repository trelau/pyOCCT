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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Interface_Graph.hxx>
#include <IGESSelect_EditHeader.hxx>
#include <IGESSelect_EditDirPart.hxx>
#include <IGESSelect_IGESTypeForm.hxx>
#include <IGESSelect_IGESName.hxx>
#include <IGESSelect_SignStatus.hxx>
#include <IGESSelect_SignLevelNumber.hxx>
#include <IGESSelect_SignColor.hxx>
#include <IGESSelect_CounterOfLevelNumber.hxx>
#include <IGESSelect_ViewSorter.hxx>
#include <IGESSelect_DispPerSingleView.hxx>
#include <IGESSelect_DispPerDrawing.hxx>
#include <IGESSelect_SelectVisibleStatus.hxx>
#include <IGESSelect_SelectSubordinate.hxx>
#include <IGESSelect_SelectLevelNumber.hxx>
#include <IGESSelect_SelectName.hxx>
#include <IGESSelect_SelectFromSingleView.hxx>
#include <IGESSelect_SelectFromDrawing.hxx>
#include <IGESSelect_SelectSingleViewFrom.hxx>
#include <IGESSelect_SelectDrawingFrom.hxx>
#include <IGESSelect_SelectBypassGroup.hxx>
#include <IGESSelect_SelectBypassSubfigure.hxx>
#include <IGESSelect_SelectBasicGeom.hxx>
#include <IGESSelect_SelectFaces.hxx>
#include <IGESSelect_SelectPCurves.hxx>
#include <IGESSelect_ModelModifier.hxx>
#include <IGESSelect_FileModifier.hxx>
#include <IGESSelect_FloatFormat.hxx>
#include <IGESSelect_AddFileComment.hxx>
#include <IGESSelect_UpdateFileName.hxx>
#include <IGESSelect_UpdateCreationDate.hxx>
#include <IGESSelect_UpdateLastChange.hxx>
#include <IGESSelect_SetVersion5.hxx>
#include <IGESSelect_SetGlobalParameter.hxx>
#include <IGESSelect_AutoCorrect.hxx>
#include <IGESSelect_ComputeStatus.hxx>
#include <IGESSelect_RebuildDrawings.hxx>
#include <IGESSelect_RebuildGroups.hxx>
#include <IGESSelect_AddGroup.hxx>
#include <IGESSelect_ChangeLevelNumber.hxx>
#include <IGESSelect_ChangeLevelList.hxx>
#include <IGESSelect_SplineToBSpline.hxx>
#include <IGESSelect_RemoveCurves.hxx>
#include <IGESSelect_SetLabel.hxx>
#include <IGESSelect_WorkLibrary.hxx>
#include <IGESSelect_Activator.hxx>
#include <IGESSelect_Dumper.hxx>
#include <IGESSelect.hxx>

void bind_IGESSelect(py::module &mod){

py::class_<IGESSelect, std::unique_ptr<IGESSelect, Deleter<IGESSelect>>> cls_IGESSelect(mod, "IGESSelect", "This package defines the library of the most used tools for IGES Files : Selections & Modifiers specific to the IGES norm, and the most needed converters");

// Constructors

// Fields

// Methods
// cls_IGESSelect.def_static("operator new_", (void * (*)(size_t)) &IGESSelect::operator new, "None", py::arg("theSize"));
// cls_IGESSelect.def_static("operator delete_", (void (*)(void *)) &IGESSelect::operator delete, "None", py::arg("theAddress"));
// cls_IGESSelect.def_static("operator new[]_", (void * (*)(size_t)) &IGESSelect::operator new[], "None", py::arg("theSize"));
// cls_IGESSelect.def_static("operator delete[]_", (void (*)(void *)) &IGESSelect::operator delete[], "None", py::arg("theAddress"));
// cls_IGESSelect.def_static("operator new_", (void * (*)(size_t, void *)) &IGESSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESSelect.def_static("operator delete_", (void (*)(void *, void *)) &IGESSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESSelect.def_static("Run_", (void (*)()) &IGESSelect::Run, "Simply gives a prompt for a conversational action on standard input/output. Returns the status of a");
cls_IGESSelect.def_static("WhatIges_", [](const opencascade::handle<IGESData_IGESEntity> & ent, const Interface_Graph & G, opencascade::handle<IGESData_IGESEntity> & sup, Standard_Integer & index){ Standard_Integer rv = IGESSelect::WhatIges(ent, G, sup, index); return std::tuple<Standard_Integer, Standard_Integer &>(rv, index); }, "Gives a quick analysis of an IGES Entity in the context of a model (i.e. a File) described by a Graph. Returned values are : : the most meaningfull super entity, if any (else Null) <index> : meaningfull index relating to super entity, if any <returned> : a status which helps exploitation of , by giving a case (normally, types of <ent> and should suffice to known the case)", py::arg("ent"), py::arg("G"), py::arg("sup"), py::arg("index"));

// Enums

}