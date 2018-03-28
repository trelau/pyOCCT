/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2018 Keith Preston

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

#include <pyOCCT_Common.hpp>

#include <xTypes.h>

#include <Aspect_DisplayConnection.hxx>
#include <Aspect_FBConfig.hxx>
#include <Xw_Window.hxx>

PYBIND11_MODULE(XwWindow, mod) {

    // IMPORT
    py::module::import("OCCT.Aspect");

    // Class definition to avoid "type not registered yet?" error.
    // (Aspect_FBConfig is a typedef of__GLXFBConfigRec)
    py::class_<__GLXFBConfigRec>(mod, "__GLXFBConfigRec");

    py::class_<Xw_Window, opencascade::handle<Xw_Window>, Aspect_Window>(mod, "Xw_Window", "This class defines XLib window intended for creation of OpenGL context.")
        //! Creates a XLib window defined by his position and size in pixels.
        //! Throws exception if window can not be created or Display do not support GLX extension.
        .def(py::init<const opencascade::handle<Aspect_DisplayConnection> &,
            const Standard_CString,
            const Standard_Integer,
            const Standard_Integer,
            const Standard_Integer,
            const Standard_Integer,
            const Aspect_FBConfig>(),
            py::arg("theXDisplay"),
            py::arg("theTitle"),
            py::arg("thePxLeft"),
            py::arg("thePxTop"),
            py::arg("thePxWidth"),
            py::arg("thePxHeight"),
            py::arg("theFBConfig") = (Aspect_FBConfig) nullptr)
        //! Creates a wrapper over existing Window handle
        .def(py::init<const opencascade::handle<Aspect_DisplayConnection> &,
            const Window,
            const Aspect_FBConfig>(),
            py::arg("theXDisplay"),
            py::arg("theWin"),
            py::arg("theFBConfig") = (Aspect_FBConfig) nullptr);

}
