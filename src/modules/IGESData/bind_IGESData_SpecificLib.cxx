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
#include <IGESData_SpecificModule.hxx>
#include <IGESData_Protocol.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESData_NodeOfSpecificLib.hxx>
#include <IGESData_SpecificLib.hxx>

void bind_IGESData_SpecificLib(py::module &mod){

py::class_<IGESData_SpecificLib, std::unique_ptr<IGESData_SpecificLib, Deleter<IGESData_SpecificLib>>> cls_IGESData_SpecificLib(mod, "IGESData_SpecificLib", "None");

// Constructors
cls_IGESData_SpecificLib.def(py::init<const opencascade::handle<IGESData_Protocol> &>(), py::arg("aprotocol"));
cls_IGESData_SpecificLib.def(py::init<>());

// Fields

// Methods
// cls_IGESData_SpecificLib.def_static("operator new_", (void * (*)(size_t)) &IGESData_SpecificLib::operator new, "None", py::arg("theSize"));
// cls_IGESData_SpecificLib.def_static("operator delete_", (void (*)(void *)) &IGESData_SpecificLib::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_SpecificLib.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_SpecificLib::operator new[], "None", py::arg("theSize"));
// cls_IGESData_SpecificLib.def_static("operator delete[]_", (void (*)(void *)) &IGESData_SpecificLib::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_SpecificLib.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_SpecificLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_SpecificLib.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_SpecificLib::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_SpecificLib.def_static("SetGlobal_", (void (*)(const opencascade::handle<IGESData_SpecificModule> &, const opencascade::handle<IGESData_Protocol> &)) &IGESData_SpecificLib::SetGlobal, "Adds a couple (Module-Protocol) into the global definition set for this class of Library.", py::arg("amodule"), py::arg("aprotocol"));
cls_IGESData_SpecificLib.def("AddProtocol", (void (IGESData_SpecificLib::*)(const opencascade::handle<Standard_Transient> &)) &IGESData_SpecificLib::AddProtocol, "Adds a couple (Module-Protocol) to the Library, given the class of a Protocol. Takes Resources into account. (if <aprotocol> is not of type TheProtocol, it is not added)", py::arg("aprotocol"));
cls_IGESData_SpecificLib.def("Clear", (void (IGESData_SpecificLib::*)()) &IGESData_SpecificLib::Clear, "Clears the list of Modules of a library (can be used to redefine the order of Modules before action : Clear then refill the Library by calls to AddProtocol)");
cls_IGESData_SpecificLib.def("SetComplete", (void (IGESData_SpecificLib::*)()) &IGESData_SpecificLib::SetComplete, "Sets a library to be defined with the complete Global list (all the couples Protocol/Modules recorded in it)");
cls_IGESData_SpecificLib.def("Select", [](IGESData_SpecificLib &self, const opencascade::handle<IGESData_IGESEntity> & obj, opencascade::handle<IGESData_SpecificModule> & module, Standard_Integer & CN){ Standard_Boolean rv = self.Select(obj, module, CN); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, CN); }, "Selects a Module from the Library, given an Object. Returns True if Select has succeeded, False else. Also Returns (as arguments) the selected Module and the Case Number determined by the associated Protocol. If Select has failed, <module> is Null Handle and CN is zero. (Select can work on any criterium, such as Object DynamicType)", py::arg("obj"), py::arg("module"), py::arg("CN"));
cls_IGESData_SpecificLib.def("Start", (void (IGESData_SpecificLib::*)()) &IGESData_SpecificLib::Start, "Starts Iteration on the Modules (sets it on the first one)");
cls_IGESData_SpecificLib.def("More", (Standard_Boolean (IGESData_SpecificLib::*)() const) &IGESData_SpecificLib::More, "Returns True if there are more Modules to iterate on");
cls_IGESData_SpecificLib.def("Next", (void (IGESData_SpecificLib::*)()) &IGESData_SpecificLib::Next, "Iterates by getting the next Module in the list If there is none, the exception will be raised by Value");
cls_IGESData_SpecificLib.def("Module", (const opencascade::handle<IGESData_SpecificModule> & (IGESData_SpecificLib::*)() const) &IGESData_SpecificLib::Module, "Returns the current Module in the Iteration");
cls_IGESData_SpecificLib.def("Protocol", (const opencascade::handle<IGESData_Protocol> & (IGESData_SpecificLib::*)() const) &IGESData_SpecificLib::Protocol, "Returns the current Protocol in the Iteration");

// Enums

}