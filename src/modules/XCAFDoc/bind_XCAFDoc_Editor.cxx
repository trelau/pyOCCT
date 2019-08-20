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
#include <TDF_Label.hxx>
#include <TDF_LabelSequence.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_Name.hxx>
#include <XCAFDoc_Editor.hxx>

void bind_XCAFDoc_Editor(py::module &mod){

py::class_<XCAFDoc_Editor, std::unique_ptr<XCAFDoc_Editor>> cls_XCAFDoc_Editor(mod, "XCAFDoc_Editor", "Tool for edit structure of document.");

// Constructors

// Fields

// Methods
// cls_XCAFDoc_Editor.def_static("operator new_", (void * (*)(size_t)) &XCAFDoc_Editor::operator new, "None", py::arg("theSize"));
// cls_XCAFDoc_Editor.def_static("operator delete_", (void (*)(void *)) &XCAFDoc_Editor::operator delete, "None", py::arg("theAddress"));
// cls_XCAFDoc_Editor.def_static("operator new[]_", (void * (*)(size_t)) &XCAFDoc_Editor::operator new[], "None", py::arg("theSize"));
// cls_XCAFDoc_Editor.def_static("operator delete[]_", (void (*)(void *)) &XCAFDoc_Editor::operator delete[], "None", py::arg("theAddress"));
// cls_XCAFDoc_Editor.def_static("operator new_", (void * (*)(size_t, void *)) &XCAFDoc_Editor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XCAFDoc_Editor.def_static("operator delete_", (void (*)(void *, void *)) &XCAFDoc_Editor::operator delete, "None", py::arg(""), py::arg(""));
cls_XCAFDoc_Editor.def_static("Expand_", [](const TDF_Label & a0, const TDF_Label & a1) -> Standard_Boolean { return XCAFDoc_Editor::Expand(a0, a1); });
cls_XCAFDoc_Editor.def_static("Expand_", (Standard_Boolean (*)(const TDF_Label &, const TDF_Label &, const Standard_Boolean)) &XCAFDoc_Editor::Expand, "Convert Shape (compound/compsolid/shell/wire) to assembly. Only compounds expanded recursively", py::arg("Doc"), py::arg("Shape"), py::arg("recursively"));
cls_XCAFDoc_Editor.def_static("Expand_", [](const TDF_Label & a0) -> Standard_Boolean { return XCAFDoc_Editor::Expand(a0); });
cls_XCAFDoc_Editor.def_static("Expand_", (Standard_Boolean (*)(const TDF_Label &, const Standard_Boolean)) &XCAFDoc_Editor::Expand, "Convert all compounds in Doc to assembly", py::arg("Doc"), py::arg("recursively"));

// Enums

}