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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Context.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <OpenGl_Clipping.hxx>
#include <NCollection_Vector.hxx>

void bind_OpenGl_Clipping(py::module &mod){

py::class_<OpenGl_Clipping> cls_OpenGl_Clipping(mod, "OpenGl_Clipping", "This class contains logics related to tracking and modification of clipping plane state for particular OpenGl context. It contains information about enabled clipping planes and provides method to change clippings in context. The methods should be executed within OpenGl context associated with instance of this class.");

// Constructors
cls_OpenGl_Clipping.def(py::init<>());

// Fields

// Methods
cls_OpenGl_Clipping.def("Init", (void (OpenGl_Clipping::*)(const Standard_Integer)) &OpenGl_Clipping::Init, "Initialize.", py::arg("theMaxPlanes"));
cls_OpenGl_Clipping.def("Reset", (void (OpenGl_Clipping::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &OpenGl_Clipping::Reset, "Setup list of global (for entire view) clipping planes and clears local plane list if it was not released before.", py::arg("theGlCtx"), py::arg("thePlanes"));
cls_OpenGl_Clipping.def("SetLocalPlanes", (void (OpenGl_Clipping::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &OpenGl_Clipping::SetLocalPlanes, "Setup list of local (for current object) clipping planes.", py::arg("theGlCtx"), py::arg("thePlanes"));
cls_OpenGl_Clipping.def("IsClippingOn", (Standard_Boolean (OpenGl_Clipping::*)() const) &OpenGl_Clipping::IsClippingOn, "Returns true if there are enabled clipping planes (NOT capping)");
cls_OpenGl_Clipping.def("IsCappingOn", (Standard_Boolean (OpenGl_Clipping::*)() const) &OpenGl_Clipping::IsCappingOn, "Returns true if there are enabled capping planes");
cls_OpenGl_Clipping.def("IsClippingOrCappingOn", (Standard_Boolean (OpenGl_Clipping::*)() const) &OpenGl_Clipping::IsClippingOrCappingOn, "Returns true if there are enabled clipping or capping planes");
cls_OpenGl_Clipping.def("NbClippingOrCappingOn", (Standard_Integer (OpenGl_Clipping::*)() const) &OpenGl_Clipping::NbClippingOrCappingOn, "Returns number of enabled clipping + capping planes");
cls_OpenGl_Clipping.def("HasDisabled", (Standard_Boolean (OpenGl_Clipping::*)() const) &OpenGl_Clipping::HasDisabled, "Return true if some clipping planes have been temporarily disabled.");
cls_OpenGl_Clipping.def("SetEnabled", (Standard_Boolean (OpenGl_Clipping::*)(const opencascade::handle<OpenGl_Context> &, const OpenGl_ClippingIterator &, const Standard_Boolean)) &OpenGl_Clipping::SetEnabled, "Disable plane temporarily.", py::arg("theGlCtx"), py::arg("thePlane"), py::arg("theIsEnabled"));
cls_OpenGl_Clipping.def("DisableGlobal", (void (OpenGl_Clipping::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Clipping::DisableGlobal, "Temporarily disable all planes from the global (view) list, keep only local (object) list.", py::arg("theGlCtx"));
cls_OpenGl_Clipping.def("RestoreDisabled", (void (OpenGl_Clipping::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Clipping::RestoreDisabled, "Restore all temporarily disabled planes. Does NOT affect constantly disabled planes Graphic3d_ClipPlane::IsOn().", py::arg("theGlCtx"));
cls_OpenGl_Clipping.def("DisableAllExcept", (void (OpenGl_Clipping::*)(const opencascade::handle<OpenGl_Context> &, const OpenGl_ClippingIterator &)) &OpenGl_Clipping::DisableAllExcept, "Temporarily disable all planes except specified one. Does not affect already disabled planes.", py::arg("theGlCtx"), py::arg("thePlane"));
cls_OpenGl_Clipping.def("EnableAllExcept", (void (OpenGl_Clipping::*)(const opencascade::handle<OpenGl_Context> &, const OpenGl_ClippingIterator &)) &OpenGl_Clipping::EnableAllExcept, "Enable back planes disabled by ::DisableAllExcept(). Keeps only specified plane enabled.", py::arg("theGlCtx"), py::arg("thePlane"));

// Enums

}