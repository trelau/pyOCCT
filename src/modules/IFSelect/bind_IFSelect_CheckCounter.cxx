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
#include <IFSelect_SignatureList.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <MoniTool_SignText.hxx>
#include <Interface_CheckIterator.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IFSelect_CheckCounter.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_CheckCounter(py::module &mod){

py::class_<IFSelect_CheckCounter, opencascade::handle<IFSelect_CheckCounter>, IFSelect_SignatureList> cls_IFSelect_CheckCounter(mod, "IFSelect_CheckCounter", "A CheckCounter allows to see a CheckList (i.e. CheckIterator) not per entity, its messages, but per message, the entities attached (count and list). Because many messages can be repeated if they are due to systematic errors");

// Constructors
cls_IFSelect_CheckCounter.def(py::init<>());
cls_IFSelect_CheckCounter.def(py::init<const Standard_Boolean>(), py::arg("withlist"));

// Fields

// Methods
cls_IFSelect_CheckCounter.def("SetSignature", (void (IFSelect_CheckCounter::*)(const opencascade::handle<MoniTool_SignText> &)) &IFSelect_CheckCounter::SetSignature, "Sets a specific signature Else, the current SignType (in the model) is used", py::arg("sign"));
cls_IFSelect_CheckCounter.def("Signature", (opencascade::handle<MoniTool_SignText> (IFSelect_CheckCounter::*)() const) &IFSelect_CheckCounter::Signature, "Returns the Signature;");
cls_IFSelect_CheckCounter.def("Analyse", [](IFSelect_CheckCounter &self, const Interface_CheckIterator & a0, const opencascade::handle<Interface_InterfaceModel> & a1) -> void { return self.Analyse(a0, a1); });
cls_IFSelect_CheckCounter.def("Analyse", [](IFSelect_CheckCounter &self, const Interface_CheckIterator & a0, const opencascade::handle<Interface_InterfaceModel> & a1, const Standard_Boolean a2) -> void { return self.Analyse(a0, a1, a2); });
cls_IFSelect_CheckCounter.def("Analyse", (void (IFSelect_CheckCounter::*)(const Interface_CheckIterator &, const opencascade::handle<Interface_InterfaceModel> &, const Standard_Boolean, const Standard_Boolean)) &IFSelect_CheckCounter::Analyse, "Analyses a CheckIterator according a Model (which detains the entities for which the CheckIterator has messages), i.e. counts messages for entities If <original> is True, does not consider final messages but those before interpretation (such as inserting variables : integers, reals, strings) If <failsonly> is True, only Fails are considered Remark : global messages are recorded with a Null entity", py::arg("list"), py::arg("model"), py::arg("original"), py::arg("failsonly"));
cls_IFSelect_CheckCounter.def_static("get_type_name_", (const char * (*)()) &IFSelect_CheckCounter::get_type_name, "None");
cls_IFSelect_CheckCounter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_CheckCounter::get_type_descriptor, "None");
cls_IFSelect_CheckCounter.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_CheckCounter::*)() const) &IFSelect_CheckCounter::DynamicType, "None");

// Enums

}