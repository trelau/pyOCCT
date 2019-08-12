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

void bind_PrsMgr_TypeOfPresentation3d(py::module &);
void bind_PrsMgr_ListOfPresentations(py::module &);
void bind_PrsMgr_PresentationManager(py::module &);
void bind_PrsMgr_PresentationManager3d(py::module &);
void bind_PrsMgr_ListOfPresentableObjects(py::module &);
void bind_PrsMgr_ListOfPresentableObjectsIter(py::module &);
void bind_PrsMgr_PresentableObjectPointer(py::module &);
void bind_PrsMgr_Presentation(py::module &);
void bind_PrsMgr_ModedPresentation(py::module &);
void bind_PrsMgr_Presentations(py::module &);
void bind_PrsMgr_PresentableObject(py::module &);
void bind_PrsMgr_Presentation3d(py::module &);
void bind_PrsMgr_PresentationPointer(py::module &);
void bind_PrsMgr_Prs(py::module &);

PYBIND11_MODULE(PrsMgr, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.V3d");
py::module::import("OCCT.Geom");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColStd");

bind_PrsMgr_TypeOfPresentation3d(mod);
bind_PrsMgr_ListOfPresentations(mod);
bind_PrsMgr_PresentationManager(mod);
bind_PrsMgr_PresentationManager3d(mod);
bind_PrsMgr_ListOfPresentableObjects(mod);
bind_PrsMgr_ListOfPresentableObjectsIter(mod);
bind_PrsMgr_PresentableObjectPointer(mod);
bind_PrsMgr_Presentation(mod);
bind_PrsMgr_ModedPresentation(mod);
bind_PrsMgr_Presentations(mod);
bind_PrsMgr_PresentableObject(mod);
bind_PrsMgr_Presentation3d(mod);
bind_PrsMgr_PresentationPointer(mod);
bind_PrsMgr_Prs(mod);

}
