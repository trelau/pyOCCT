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
#include <BRepMesh_DiscretFactory.hxx>
#include <TColStd_MapOfAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <BRepMesh_FactoryError.hxx>
#include <Standard_Handle.hxx>
#include <BRepMesh_DiscretRoot.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepMesh_PluginEntryType.hxx>
#include <Plugin_MapOfFunctions.hxx>

void bind_BRepMesh_DiscretFactory(py::module &mod){

py::class_<BRepMesh_DiscretFactory, std::unique_ptr<BRepMesh_DiscretFactory, py::nodelete>> cls_BRepMesh_DiscretFactory(mod, "BRepMesh_DiscretFactory", "This class intended to setup / retrieve default triangulation algorithm. Use BRepMesh_DiscretFactory::Get() static method to retrieve global Factory instance. Use BRepMesh_DiscretFactory::Discret() method to retrieve meshing tool.");

// Constructors

// Fields

// Methods
// cls_BRepMesh_DiscretFactory.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_DiscretFactory::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_DiscretFactory.def_static("operator delete_", (void (*)(void *)) &BRepMesh_DiscretFactory::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_DiscretFactory.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_DiscretFactory::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_DiscretFactory.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_DiscretFactory::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_DiscretFactory.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_DiscretFactory::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_DiscretFactory.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_DiscretFactory::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_DiscretFactory.def_static("Get_", (BRepMesh_DiscretFactory & (*)()) &BRepMesh_DiscretFactory::Get, "Returns the global factory instance.");
cls_BRepMesh_DiscretFactory.def("Names", (const TColStd_MapOfAsciiString & (BRepMesh_DiscretFactory::*)() const) &BRepMesh_DiscretFactory::Names, "Returns the list of registered meshing algorithms.");
cls_BRepMesh_DiscretFactory.def("SetDefaultName", (Standard_Boolean (BRepMesh_DiscretFactory::*)(const TCollection_AsciiString &)) &BRepMesh_DiscretFactory::SetDefaultName, "Setup meshing algorithm by name. Returns TRUE if requested tool is available. On fail Factory will continue to use previous algo.", py::arg("theName"));
cls_BRepMesh_DiscretFactory.def("DefaultName", (const TCollection_AsciiString & (BRepMesh_DiscretFactory::*)() const) &BRepMesh_DiscretFactory::DefaultName, "Returns name for current meshing algorithm.");
cls_BRepMesh_DiscretFactory.def("SetFunctionName", (Standard_Boolean (BRepMesh_DiscretFactory::*)(const TCollection_AsciiString &)) &BRepMesh_DiscretFactory::SetFunctionName, "Advanced function. Changes function name to retrieve from plugin. Returns TRUE if requested tool is available. On fail Factory will continue to use previous algo.", py::arg("theFuncName"));
cls_BRepMesh_DiscretFactory.def("FunctionName", (const TCollection_AsciiString & (BRepMesh_DiscretFactory::*)() const) &BRepMesh_DiscretFactory::FunctionName, "Returns function name that should be exported by plugin.");
cls_BRepMesh_DiscretFactory.def("ErrorStatus", (BRepMesh_FactoryError (BRepMesh_DiscretFactory::*)() const) &BRepMesh_DiscretFactory::ErrorStatus, "Returns error status for last meshing algorithm switch.");
cls_BRepMesh_DiscretFactory.def("SetDefault", [](BRepMesh_DiscretFactory &self, const TCollection_AsciiString & a0) -> Standard_Boolean { return self.SetDefault(a0); });
cls_BRepMesh_DiscretFactory.def("SetDefault", (Standard_Boolean (BRepMesh_DiscretFactory::*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &BRepMesh_DiscretFactory::SetDefault, "Setup meshing algorithm that should be created by this Factory. Returns TRUE if requested tool is available. On fail Factory will continue to use previous algo. Call ::ErrorStatus() method to retrieve fault reason.", py::arg("theName"), py::arg("theFuncName"));
cls_BRepMesh_DiscretFactory.def("Discret", (opencascade::handle<BRepMesh_DiscretRoot> (BRepMesh_DiscretFactory::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real)) &BRepMesh_DiscretFactory::Discret, "Returns triangulation algorithm instance.", py::arg("theShape"), py::arg("theLinDeflection"), py::arg("theAngDeflection"));

// Enums

}