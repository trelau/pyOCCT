/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#ifndef __OpenGl_Templates_Header__
#define __OpenGl_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <OpenGl_MatrixState.hxx>
#include <OpenGl_Texture.hxx>
#include <OpenGl_GlCore12.hxx>
#include <OpenGl_GlCore14.hxx>
#include <OpenGl_GlCore15.hxx>
#include <OpenGl_GlCore20.hxx>
#include <OpenGl_GlCore21.hxx>
#include <OpenGl_GlCore30.hxx>
#include <OpenGl_GlCore31.hxx>
#include <OpenGl_GlCore32.hxx>
#include <OpenGl_GlCore33.hxx>
#include <OpenGl_GlCore40.hxx>
#include <OpenGl_GlCore41.hxx>
#include <OpenGl_GlCore42.hxx>
#include <OpenGl_GlCore43.hxx>
#include <OpenGl_GlCore44.hxx>
#include <OpenGl_ShaderProgram.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Context.hxx>
#include <Graphic3d_ShaderVariable.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_VertexBuffer.hxx>
#include <OpenGl_VertexBufferEditor.hxx>

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_MatrixState.hxx
template <typename T>
void bind_OpenGl_MatrixState(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_MatrixState.hxx
	py::class_<OpenGl_MatrixState<T>, std::unique_ptr<OpenGl_MatrixState<T>, Deleter<OpenGl_MatrixState<T>>>> cls(mod, name.c_str(), "Software implementation for OpenGL matrix stack.");
	cls.def(py::init<>());
	cls.def("Push", (void (OpenGl_MatrixState<T>::*)()) &OpenGl_MatrixState<T>::Push, "Pushes current matrix into stack.");
	cls.def("Pop", (void (OpenGl_MatrixState<T>::*)()) &OpenGl_MatrixState<T>::Pop, "Pops matrix from stack to current.");
	cls.def("Current", (const typename OpenGl::MatrixType<T>::Mat4 & (OpenGl_MatrixState<T>::*)()) &OpenGl_MatrixState<T>::Current, "Returns current matrix.");
	cls.def("SetCurrent", (void (OpenGl_MatrixState<T>::*)(const typename OpenGl::MatrixType<T>::Mat4 &)) &OpenGl_MatrixState<T>::SetCurrent, "Sets given matrix as current.", py::arg("theNewCurrent"));
	cls.def("ChangeCurrent", (typename OpenGl::MatrixType<T>::Mat4 & (OpenGl_MatrixState<T>::*)()) &OpenGl_MatrixState<T>::ChangeCurrent, "Change current matrix.");
	cls.def("SetIdentity", (void (OpenGl_MatrixState<T>::*)()) &OpenGl_MatrixState<T>::SetIdentity, "Sets current matrix to identity.");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_Texture.hxx
template <typename T>
void bind_OpenGl_TextureFormatSelector(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_Texture.hxx
	py::class_<OpenGl_TextureFormatSelector<T>, std::unique_ptr<OpenGl_TextureFormatSelector<T>, Deleter<OpenGl_TextureFormatSelector<T>>>> cls(mod, name.c_str(), "Selects preferable texture format for specified parameters.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore12.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore12(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore12.hxx
	py::class_<OpenGl_TmplCore12<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore12<theBaseClass_t>, Deleter<OpenGl_TmplCore12<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 1.2 core based on 1.1 version.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore14.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore14(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore14.hxx
	py::class_<OpenGl_TmplCore14<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore14<theBaseClass_t>, Deleter<OpenGl_TmplCore14<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 1.4 core based on 1.3 version.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore15.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore15(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore15.hxx
	py::class_<OpenGl_TmplCore15<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore15<theBaseClass_t>, Deleter<OpenGl_TmplCore15<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 1.5 core based on 1.4 version.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore20.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore20(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore20.hxx
	py::class_<OpenGl_TmplCore20<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore20<theBaseClass_t>, Deleter<OpenGl_TmplCore20<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 2.0 core based on 1.5 version.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore21.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore21(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore21.hxx
	py::class_<OpenGl_TmplCore21<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore21<theBaseClass_t>, Deleter<OpenGl_TmplCore21<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 2.1 core based on 2.0 version.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore30.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore30(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore30.hxx
	py::class_<OpenGl_TmplCore30<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore30<theBaseClass_t>, Deleter<OpenGl_TmplCore30<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 3.0 core. This is first version with deprecation model introduced - a lot of functionality regarding to fixed pipeline were marked deprecated. Notice that nothing were actually removed in this version (unless Forward context loaded)!");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore31.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore31(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore31.hxx
	py::class_<OpenGl_TmplCore31<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore31<theBaseClass_t>, Deleter<OpenGl_TmplCore31<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 3.1 definition.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore32.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore32(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore32.hxx
	py::class_<OpenGl_TmplCore32<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore32<theBaseClass_t>, Deleter<OpenGl_TmplCore32<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 3.2 definition.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore33.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore33(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore33.hxx
	py::class_<OpenGl_TmplCore33<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore33<theBaseClass_t>, Deleter<OpenGl_TmplCore33<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 3.3 definition.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore40.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore40(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore40.hxx
	py::class_<OpenGl_TmplCore40<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore40<theBaseClass_t>, Deleter<OpenGl_TmplCore40<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 4.0 definition.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore41.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore41(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore41.hxx
	py::class_<OpenGl_TmplCore41<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore41<theBaseClass_t>, Deleter<OpenGl_TmplCore41<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 4.1 definition.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore42.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore42(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore42.hxx
	py::class_<OpenGl_TmplCore42<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore42<theBaseClass_t>, Deleter<OpenGl_TmplCore42<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 4.2 definition.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore43.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore43(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore43.hxx
	py::class_<OpenGl_TmplCore43<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore43<theBaseClass_t>, Deleter<OpenGl_TmplCore43<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 4.3 definition.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore44.hxx
template <typename theBaseClass_t>
void bind_OpenGl_TmplCore44(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_GlCore44.hxx
	py::class_<OpenGl_TmplCore44<theBaseClass_t>, std::unique_ptr<OpenGl_TmplCore44<theBaseClass_t>, Deleter<OpenGl_TmplCore44<theBaseClass_t>>>, theBaseClass_t> cls(mod, name.c_str(), "OpenGL 4.4 definition.");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_ShaderProgram.hxx
template <typename T>
void bind_OpenGl_VariableSetter(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_ShaderProgram.hxx
	py::class_<OpenGl_VariableSetter<T>, std::unique_ptr<OpenGl_VariableSetter<T>, Deleter<OpenGl_VariableSetter<T>>>, OpenGl_SetterInterface> cls(mod, name.c_str(), "None");
	cls.def(py::init<>());
	cls.def("Set", (void (OpenGl_VariableSetter<T>::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_ShaderVariable> &, OpenGl_ShaderProgram *)) &OpenGl_VariableSetter<T>::Set, "None", py::arg("theCtx"), py::arg("theVariable"), py::arg("theProgram"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_VertexBufferEditor.hxx
template <typename theVec_t>
void bind_OpenGl_VertexBufferEditor(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\OpenGl_VertexBufferEditor.hxx
	py::class_<OpenGl_VertexBufferEditor<theVec_t>, std::unique_ptr<OpenGl_VertexBufferEditor<theVec_t>, Deleter<OpenGl_VertexBufferEditor<theVec_t>>>> cls(mod, name.c_str(), "Auxiliary class to iteratively modify data of existing VBO. It provides iteration interface with delayed CPU->GPU memory transfer to avoid slow per-element data transfer. User should explicitly call Flush() method to ensure that all data is transferred to VBO. Temporary buffer on CPU side can be initialized with lesser capacity than VBO to allow re-usage of shared buffer with fixed size between VBOs.");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer>(), py::arg("theTmpBufferLength"));
	cls.def(py::init<theVec_t *, const Standard_Integer>(), py::arg("theTmpBuffer"), py::arg("theTmpBufferLength"));
	cls.def("Init", (Standard_Boolean (OpenGl_VertexBufferEditor<theVec_t>::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<OpenGl_VertexBuffer> &)) &OpenGl_VertexBufferEditor<theVec_t>::Init, "Initialize editor for specified VBO. theGlCtx - bound OpenGL context to edit VBO theVbo - VBO to edit", py::arg("theGlCtx"), py::arg("theVbo"));
	cls.def("Value", (theVec_t & (OpenGl_VertexBufferEditor<theVec_t>::*)()) &OpenGl_VertexBufferEditor<theVec_t>::Value, "Modify current element in VBO.");
	cls.def("Next", (Standard_Boolean (OpenGl_VertexBufferEditor<theVec_t>::*)()) &OpenGl_VertexBufferEditor<theVec_t>::Next, "Move to the next position in VBO.");
	cls.def("Flush", (Standard_Boolean (OpenGl_VertexBufferEditor<theVec_t>::*)()) &OpenGl_VertexBufferEditor<theVec_t>::Flush, "Push current data from local buffer to VBO.");
	cls.def("GetVBO", (const opencascade::handle<OpenGl_VertexBuffer> & (OpenGl_VertexBufferEditor<theVec_t>::*)() const ) &OpenGl_VertexBufferEditor<theVec_t>::GetVBO, "Returns assigned VBO");

};

#endif