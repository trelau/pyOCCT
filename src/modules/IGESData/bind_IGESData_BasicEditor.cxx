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
#include <Standard_Handle.hxx>
#include <IGESData_Protocol.hxx>
#include <IGESData_IGESModel.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Interface_GeneralLib.hxx>
#include <IGESData_SpecificLib.hxx>
#include <IGESData_BasicEditor.hxx>

void bind_IGESData_BasicEditor(py::module &mod){

py::class_<IGESData_BasicEditor, std::unique_ptr<IGESData_BasicEditor, Deleter<IGESData_BasicEditor>>> cls_IGESData_BasicEditor(mod, "IGESData_BasicEditor", "This class provides various functions of basic edition, such as : - setting header unit (WARNING : DOES NOT convert entities) - computation of the status (Subordinate, UseFlag) of entities of IGES Entities on a whole model - auto correction of IGES Entities, defined both by DirChecker and by specific service AutoCorrect (this auto correction performs non-ambigious, rather logic, editions)");

// Constructors
cls_IGESData_BasicEditor.def(py::init<>());
cls_IGESData_BasicEditor.def(py::init<const opencascade::handle<IGESData_Protocol> &>(), py::arg("protocol"));
cls_IGESData_BasicEditor.def(py::init<const opencascade::handle<IGESData_IGESModel> &, const opencascade::handle<IGESData_Protocol> &>(), py::arg("model"), py::arg("protocol"));

// Fields

// Methods
// cls_IGESData_BasicEditor.def_static("operator new_", (void * (*)(size_t)) &IGESData_BasicEditor::operator new, "None", py::arg("theSize"));
// cls_IGESData_BasicEditor.def_static("operator delete_", (void (*)(void *)) &IGESData_BasicEditor::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_BasicEditor.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_BasicEditor::operator new[], "None", py::arg("theSize"));
// cls_IGESData_BasicEditor.def_static("operator delete[]_", (void (*)(void *)) &IGESData_BasicEditor::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_BasicEditor.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_BasicEditor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_BasicEditor.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_BasicEditor::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_BasicEditor.def("Init", (void (IGESData_BasicEditor::*)(const opencascade::handle<IGESData_Protocol> &)) &IGESData_BasicEditor::Init, "Initialize a Basic Editor, with a new IGESModel, ready to run", py::arg("protocol"));
cls_IGESData_BasicEditor.def("Init", (void (IGESData_BasicEditor::*)(const opencascade::handle<IGESData_IGESModel> &, const opencascade::handle<IGESData_Protocol> &)) &IGESData_BasicEditor::Init, "Initialize a Basic Editor for IGES Data, ready to run", py::arg("model"), py::arg("protocol"));
cls_IGESData_BasicEditor.def("Model", (opencascade::handle<IGESData_IGESModel> (IGESData_BasicEditor::*)() const) &IGESData_BasicEditor::Model, "Returns the designated model");
cls_IGESData_BasicEditor.def("SetUnitFlag", (Standard_Boolean (IGESData_BasicEditor::*)(const Standard_Integer)) &IGESData_BasicEditor::SetUnitFlag, "Sets a new unit from its flag (param 14 of Global Section) Returns True if done, False if <flag> is incorrect", py::arg("flag"));
cls_IGESData_BasicEditor.def("SetUnitValue", (Standard_Boolean (IGESData_BasicEditor::*)(const Standard_Real)) &IGESData_BasicEditor::SetUnitValue, "Sets a new unit from its value in meters (rounded to the closest one, max gap 1%) Returns True if done, False if <val> is too far from a suitable value", py::arg("val"));
cls_IGESData_BasicEditor.def("SetUnitName", (Standard_Boolean (IGESData_BasicEditor::*)(const Standard_CString)) &IGESData_BasicEditor::SetUnitName, "Sets a new unit from its name (param 15 of Global Section) Returns True if done, False if <name> is incorrect Remark : if <flag> has been set to 3 (user defined), <name> is then free", py::arg("name"));
cls_IGESData_BasicEditor.def("ApplyUnit", [](IGESData_BasicEditor &self) -> void { return self.ApplyUnit(); });
cls_IGESData_BasicEditor.def("ApplyUnit", (void (IGESData_BasicEditor::*)(const Standard_Boolean)) &IGESData_BasicEditor::ApplyUnit, "Applies unit value to convert header data : Resolution, MaxCoord, MaxLineWeight Applies unit only once after SetUnit... has been called, if <enforce> is given as True. It can be called just before writing the model to a file, i.e. when definitive values are finally known", py::arg("enforce"));
cls_IGESData_BasicEditor.def("ComputeStatus", (void (IGESData_BasicEditor::*)()) &IGESData_BasicEditor::ComputeStatus, "Performs the re-computation of status on the whole model (Subordinate Status and Use Flag of each IGES Entity), which can have required values according the way they are referenced (see definitions of Logical use, Physical use, etc...)");
cls_IGESData_BasicEditor.def("AutoCorrect", (Standard_Boolean (IGESData_BasicEditor::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_BasicEditor::AutoCorrect, "Performs auto-correction on an IGESEntity Returns True if something has changed, False if nothing done.", py::arg("ent"));
cls_IGESData_BasicEditor.def("AutoCorrectModel", (Standard_Integer (IGESData_BasicEditor::*)()) &IGESData_BasicEditor::AutoCorrectModel, "Performs auto-correction on the whole Model Returns the count of modified entities");
cls_IGESData_BasicEditor.def_static("UnitNameFlag_", (Standard_Integer (*)(const Standard_CString)) &IGESData_BasicEditor::UnitNameFlag, "From the name of unit, computes flag number, 0 if incorrect (in this case, user defined entity remains possible)", py::arg("name"));
cls_IGESData_BasicEditor.def_static("UnitFlagValue_", (Standard_Real (*)(const Standard_Integer)) &IGESData_BasicEditor::UnitFlagValue, "From the flag of unit, determines value in MM, 0 if incorrect", py::arg("flag"));
cls_IGESData_BasicEditor.def_static("UnitFlagName_", (Standard_CString (*)(const Standard_Integer)) &IGESData_BasicEditor::UnitFlagName, "From the flag of unit, determines its name, '' if incorrect", py::arg("flag"));
cls_IGESData_BasicEditor.def_static("IGESVersionName_", (Standard_CString (*)(const Standard_Integer)) &IGESData_BasicEditor::IGESVersionName, "From the flag of IGES version, returns name, '' if incorrect", py::arg("flag"));
cls_IGESData_BasicEditor.def_static("IGESVersionMax_", (Standard_Integer (*)()) &IGESData_BasicEditor::IGESVersionMax, "Returns the maximum allowed value for IGESVersion Flag");
cls_IGESData_BasicEditor.def_static("DraftingName_", (Standard_CString (*)(const Standard_Integer)) &IGESData_BasicEditor::DraftingName, "From the flag of drafting standard, returns name, '' if incorrect", py::arg("flag"));
cls_IGESData_BasicEditor.def_static("DraftingMax_", (Standard_Integer (*)()) &IGESData_BasicEditor::DraftingMax, "Returns the maximum allowed value for Drafting Flag");

// Enums

}