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
#include <Interface_GeneralModule.hxx>
#include <Interface_Protocol.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_NodeOfGeneralLib.hxx>
#include <Interface_GeneralLib.hxx>

void bind_Interface_GeneralLib(py::module &mod){

py::class_<Interface_GeneralLib, std::unique_ptr<Interface_GeneralLib, Deleter<Interface_GeneralLib>>> cls_Interface_GeneralLib(mod, "Interface_GeneralLib", "None");

// Constructors
cls_Interface_GeneralLib.def(py::init<const opencascade::handle<Interface_Protocol> &>(), py::arg("aprotocol"));
cls_Interface_GeneralLib.def(py::init<>());

// Fields

// Methods
// cls_Interface_GeneralLib.def_static("operator new_", (void * (*)(size_t)) &Interface_GeneralLib::operator new, "None", py::arg("theSize"));
// cls_Interface_GeneralLib.def_static("operator delete_", (void (*)(void *)) &Interface_GeneralLib::operator delete, "None", py::arg("theAddress"));
// cls_Interface_GeneralLib.def_static("operator new[]_", (void * (*)(size_t)) &Interface_GeneralLib::operator new[], "None", py::arg("theSize"));
// cls_Interface_GeneralLib.def_static("operator delete[]_", (void (*)(void *)) &Interface_GeneralLib::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_GeneralLib.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_GeneralLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_GeneralLib.def_static("operator delete_", (void (*)(void *, void *)) &Interface_GeneralLib::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_GeneralLib.def_static("SetGlobal_", (void (*)(const opencascade::handle<Interface_GeneralModule> &, const opencascade::handle<Interface_Protocol> &)) &Interface_GeneralLib::SetGlobal, "Adds a couple (Module-Protocol) into the global definition set for this class of Library.", py::arg("amodule"), py::arg("aprotocol"));
cls_Interface_GeneralLib.def("AddProtocol", (void (Interface_GeneralLib::*)(const opencascade::handle<Standard_Transient> &)) &Interface_GeneralLib::AddProtocol, "Adds a couple (Module-Protocol) to the Library, given the class of a Protocol. Takes Resources into account. (if <aprotocol> is not of type TheProtocol, it is not added)", py::arg("aprotocol"));
cls_Interface_GeneralLib.def("Clear", (void (Interface_GeneralLib::*)()) &Interface_GeneralLib::Clear, "Clears the list of Modules of a library (can be used to redefine the order of Modules before action : Clear then refill the Library by calls to AddProtocol)");
cls_Interface_GeneralLib.def("SetComplete", (void (Interface_GeneralLib::*)()) &Interface_GeneralLib::SetComplete, "Sets a library to be defined with the complete Global list (all the couples Protocol/Modules recorded in it)");
cls_Interface_GeneralLib.def("Select", [](Interface_GeneralLib &self, const opencascade::handle<Standard_Transient> & obj, opencascade::handle<Interface_GeneralModule> & module, Standard_Integer & CN){ Standard_Boolean rv = self.Select(obj, module, CN); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, CN); }, "Selects a Module from the Library, given an Object. Returns True if Select has succeeded, False else. Also Returns (as arguments) the selected Module and the Case Number determined by the associated Protocol. If Select has failed, <module> is Null Handle and CN is zero. (Select can work on any criterium, such as Object DynamicType)", py::arg("obj"), py::arg("module"), py::arg("CN"));
cls_Interface_GeneralLib.def("Start", (void (Interface_GeneralLib::*)()) &Interface_GeneralLib::Start, "Starts Iteration on the Modules (sets it on the first one)");
cls_Interface_GeneralLib.def("More", (Standard_Boolean (Interface_GeneralLib::*)() const) &Interface_GeneralLib::More, "Returns True if there are more Modules to iterate on");
cls_Interface_GeneralLib.def("Next", (void (Interface_GeneralLib::*)()) &Interface_GeneralLib::Next, "Iterates by getting the next Module in the list If there is none, the exception will be raised by Value");
cls_Interface_GeneralLib.def("Module", (const opencascade::handle<Interface_GeneralModule> & (Interface_GeneralLib::*)() const) &Interface_GeneralLib::Module, "Returns the current Module in the Iteration");
cls_Interface_GeneralLib.def("Protocol", (const opencascade::handle<Interface_Protocol> & (Interface_GeneralLib::*)() const) &Interface_GeneralLib::Protocol, "Returns the current Protocol in the Iteration");

// Enums

}