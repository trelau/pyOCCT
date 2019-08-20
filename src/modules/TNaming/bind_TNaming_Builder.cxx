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
#include <TDF_Label.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <TNaming_NamedShape.hxx>
#include <TNaming_UsedShapes.hxx>
#include <TNaming_Builder.hxx>

void bind_TNaming_Builder(py::module &mod){

py::class_<TNaming_Builder, std::unique_ptr<TNaming_Builder>> cls_TNaming_Builder(mod, "TNaming_Builder", "A tool to create and maintain topological attributes. Constructor creates an empty TNaming_NamedShape attribute at the given label. It allows adding 'old shape' and 'new shape' pairs with the specified evolution to this named shape. One evolution type per one builder must be used.");

// Constructors
cls_TNaming_Builder.def(py::init<const TDF_Label &>(), py::arg("aLabel"));

// Fields

// Methods
// cls_TNaming_Builder.def_static("operator new_", (void * (*)(size_t)) &TNaming_Builder::operator new, "None", py::arg("theSize"));
// cls_TNaming_Builder.def_static("operator delete_", (void (*)(void *)) &TNaming_Builder::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_Builder.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_Builder::operator new[], "None", py::arg("theSize"));
// cls_TNaming_Builder.def_static("operator delete[]_", (void (*)(void *)) &TNaming_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_Builder.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_Builder.def("Generated", (void (TNaming_Builder::*)(const TopoDS_Shape &)) &TNaming_Builder::Generated, "Records the shape newShape which was generated during a topological construction. As an example, consider the case of a face generated in construction of a box.", py::arg("newShape"));
cls_TNaming_Builder.def("Generated", (void (TNaming_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TNaming_Builder::Generated, "Records the shape newShape which was generated from the shape oldShape during a topological construction. As an example, consider the case of a face generated from an edge in construction of a prism.", py::arg("oldShape"), py::arg("newShape"));
cls_TNaming_Builder.def("Delete", (void (TNaming_Builder::*)(const TopoDS_Shape &)) &TNaming_Builder::Delete, "Records the shape oldShape which was deleted from the current label. As an example, consider the case of a face removed by a Boolean operation.", py::arg("oldShape"));
cls_TNaming_Builder.def("Modify", (void (TNaming_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TNaming_Builder::Modify, "Records the shape newShape which is a modification of the shape oldShape. As an example, consider the case of a face split or merged in a Boolean operation.", py::arg("oldShape"), py::arg("newShape"));
cls_TNaming_Builder.def("Select", (void (TNaming_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TNaming_Builder::Select, "Add a Shape to the current label , This Shape is unmodified. Used for example to define a set of shapes under a label.", py::arg("aShape"), py::arg("inShape"));
cls_TNaming_Builder.def("NamedShape", (opencascade::handle<TNaming_NamedShape> (TNaming_Builder::*)() const) &TNaming_Builder::NamedShape, "Returns the NamedShape which has been built or is under construction.");

// Enums

}